/*
** EPITECH PROJECT, 2023
** check_clients
** File description:
** check_client
*/

#include "../include/sv_functiontype.h"

void accept_Clients(int serverSocket, Client* clients, int* numClients, const Map* map)
{
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress,
    &clientAddressLength);
    if (clientSocket == -1) {
        perror("Failed to accept client connection");
        return;
    }
    Client client;
    client.socket = clientSocket;
    client.id = (*numClients) + 1;
    client.x = 0;
    client.y = map->height / 2;
    client.score = 0;
    client.jpState = 0;
    clients[*numClients] = client;
    (*numClients)++;
    printf("Client %d connected.\n", client.id);
    if (*numClients >= MAX_CLIENTS) {
        printf("Game started!\n");
    }
}

void handleClient_Requests(Client* client, const Client* clients, int numClients, const Map* map) {
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytesRead = read(client->socket, buffer, BUFFER_SIZE - 1);
        if (bytesRead <= 0) {
            printf("Client %d disconnected.\n", client->id);
            close(client->socket);
            return;
        }
        buffer[bytesRead] = '\0';
        handle_Request(client, clients, numClients, buffer, map);
    }
}
