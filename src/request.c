/*
** EPITECH PROJECT, 2023
** request.c
** File description:
** client_to_server_vice_versa
*/

#include "../include/sv_functiontype.h"

void sendMessage_ToClient(int clientSocket, const char* message)
{
    write(clientSocket, message, strlen(message));
}

void broadcast_Message(const Client* clients, int numClients, const char* message)
{
    for (int i = 0; i < numClients; i++) {
        sendMessage_ToClient(clients[i].socket, message);
    }
}

void handle_Request(Client* client, const Client* clients, int numClients, const char* request, const Map* map)
{
    if (strncmp(request, "ID", 2) == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "ID %d\n", client->id);
        sendMessage_ToClient(client->socket, response);
    } else if (strncmp(request, "MAP", 3) == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "MAP %.1f %d %d %s\n", map->gravity, map->width, map->height, map->cells);
        sendMessage_ToClient(client->socket, response);
    } else if (strncmp(request, "READY", 5) == 0) {
        char response[BUFFER_SIZE] = "START\n";
        broadcast_Message(clients, numClients, response);
    } else if (strncmp(request, "FIRE", 4) == 0) {
        int state;
        sscanf(request, "FIRE %d", &state);
        client->jpState = state;
        char message[BUFFER_SIZE];
        snprintf(message, BUFFER_SIZE,
        "PLAYER %d %d %d %d %d\n", client->id,
        client->x, client->y, client->score, client->jpState);
        broadcast_Message(clients, numClients, message);
    } else {
        return;
    }
}
