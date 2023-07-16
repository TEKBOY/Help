/*
** EPITECH PROJECT, 2023
** check_clients
** File description:
** check_client
*/

#include "../include/sv_functiontype.h"

void acceptclient(int socket, Client* clients, int* numclients, const Map* map)
{
    struct sockaddr_in clientadd;
    socklen_t clientaddlength = sizeof(clientadd);
    int clientsocket = accept(socket, (struct sockaddr*)&clientadd,
    &clientaddlength);
    if (clientsocket == -1) {
        perror("Failed to accept client connection");
        return;
    } Client client;
    client.socket = clientsocket;
    client.id = (*numclients) + 1; client.x = 0;
    client.y = map->height / 2;
    client.score = 0; client.state = 0;
    clients[*numclients] = client;
    (*numclients)++;
    printf("Client %d connected.\n", client.id);
    if (*numclients >= MAX_CLIENTS) {
        printf("Game started!\n");
    }
}

void handleclientrequests(Client* client, const Client* clients, int numclients, const Map* map)
{
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytesread = read(client->socket, buffer, BUFFER_SIZE - 1);
        if (bytesread <= 0) {
            printf("Client %d disconnected.\n", client->id);
            close(client->socket);
            return;
        }
        buffer[bytesread] = '\0';
        handlerequest(client, clients, numclients, buffer, map);
    }
}
