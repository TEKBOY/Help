/*
** EPITECH PROJECT, 2023
** game_logic.c
** File description:
** all_game_action_&_condition
*/

#include "../include/sv_functiontype.h"

int is_Collision(int x, int y, char* cells, int width, int height)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return 1;

    char cell = cells[y * width + x];
    return (cell == 'e' || cell == 'c');
}

void update_PlayerPosition(Client* client, int newX, int newY, char* cells, int width, int height, const Client* clients, int numClients)
{
    if (is_Collision(newX, newY, cells, width, height))
        return;

    client->x = newX;
    client->y = newY;
    if (cells[newY * width + newX] == 'c') {
        cells[newY * width + newX] = '_';
        client->score++;
        char message[BUFFER_SIZE];
        snprintf(message, BUFFER_SIZE, "COIN %d %d %d\n", client->id, newX, newY);
        broadcast_Message(clients, numClients, message);
    }
    if (newX >= width - 1) {
        int winnerID = -1;
        int maxScore = -1;
        for (int i = 0; i < numClients; i++) {
            if (clients[i].score > maxScore) {
                maxScore = clients[i].score;
                winnerID = clients[i].id;
            }
        }
        char message[BUFFER_SIZE];
        snprintf(message, BUFFER_SIZE, "FINISH %d\n", winnerID);
        broadcast_Message(clients, numClients, message);
    }
}
