/*
** EPITECH PROJECT, 2023
** jet_server.c
** File description:
** project_server_gestion
*/

#include "../include/sv_functiontype.h"

void initialize_ServerSocket(int* serverSocket, int port)
{
    *serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (*serverSocket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(*serverSocket, (struct sockaddr*)&serverAddress,
    sizeof(serverAddress)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(*serverSocket, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }
    printf("Listening on port %d\nWaiting for connections...\n", port);
}

void runServer(int serverSocket, const Map* map)
{
    Client clients[MAX_CLIENTS];
    int numClients = 0;

    while (1) {
        accept_Clients(serverSocket, clients, &numClients, map);
        if (numClients >= MAX_CLIENTS) {
            for (int i = 0; i < numClients; i++) {
                handleClient_Requests(&clients[i],
                clients, numClients, map);
            }
            break;
        }
    }
    close(serverSocket);
    free(map->cells);
}

void executeServer(int port, const Map* map) {
    int serverSocket;
    initialize_ServerSocket(&serverSocket, port);
    runServer(serverSocket, map);
}
