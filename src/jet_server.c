/*
** EPITECH PROJECT, 2023
** jet_server.c
** File description:
** project_server_gestion
*/

#include "../include/sv_functiontype.h"

void initialize(int* sockett, int port)
{
    *sockett = socket(AF_INET, SOCK_STREAM, 0);;
    if (*sockett == -1) {
        perror("Failed to create sockett");
        exit(1);
    }
    struct sockaddr_in serveradd;
    serveradd.sin_family = AF_INET;
    serveradd.sin_addr.s_addr = INADDR_ANY;
    serveradd.sin_port = htons(port);
    if (bind(*sockett, (struct sockaddr*)&serveradd,
    sizeof(serveradd)) == -1) {
        perror("Failed to bind sockett");
        exit(1);
    }
    if (listen(*sockett, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }
    printf("Listening on port %d\n", port);
    printf("Waiting for connections...\n");
}

void run(int sockett, const Map* map)
{
    Client clients[MAX_CLIENTS];
    int numclients = 0;

    while (1) {
        acceptclient(sockett, clients, &numclients, map);
        if (numclients >= MAX_CLIENTS) {
            for (int i = 0; i < numclients; i++) {
                handleclientrequests(&clients[i],
                clients, numclients, map);
            }
            break;
        }
    }
    close(sockett);
    free(map->cells);
}

void execute(int port, const Map* map)
{
    int sockett;
    initialize(&sockett, port);
    run(sockett, map);
}
