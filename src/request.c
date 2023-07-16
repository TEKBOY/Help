/*
** EPITECH PROJECT, 2023
** request.c
** File description:
** client_to_server_vice_versa
*/

#include "../include/sv_functiontype.h"

void sendmessage(int clientSocket, const char* message)
{
    write(clientSocket, message, strlen(message));
}

void broadcast_Message(const Client* clients, int numclients, const char* message)
{
    for (int i = 0; i < numclients; i++) {
        sendmessage(clients[i].socket, message);
    }
}

void handlerequest(Client* client, const Client* clients, int numclients, const char* request, const Map* map)
{
    if (strncmp(request, "ID", 2) == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "ID %d\n", client->id);
        sendmessage(client->socket, response);
    } else if (strncmp(request, "MAP", 3) == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "MAP %.1f %d %d %s\n", map->gravity, map->width, map->height, map->cells);
        sendmessage(client->socket, response);
    } else if (strncmp(request, "READY", 5) == 0) {
        char response[BUFFER_SIZE] = "START\n";
        broadcast_Message(clients, numclients, response);
    } else if (strncmp(request, "FIRE", 4) == 0) {
        int state; sscanf(request, "FIRE %d", &state);
        client->state = state;
        char message[BUFFER_SIZE];
        snprintf(message, BUFFER_SIZE,
        "PLAYER %d %d %d %d %d\n", client->id,
        client->x, client->y, client->score, client->state);
        broadcast_Message(clients, numclients, message);
    } else {return;}
}
