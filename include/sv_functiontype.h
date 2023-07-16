/*
** EPITECH PROJECT, 2023
** sv_functiontype.h
** File description:
** all_server_&_support_prototype
*/

#include "server.h"

#ifndef SV_FUNCTIONTYPE_H_f
    #define SV_FUNCTIONTYPE_H_

int is_Collision(int x, int y, char* cells, int width, int height);
void update_PlayerPosition(Client* client, int newX, int newY, char* cells, int width, int height, const Client* clients, int numClients);
void sendMessage_ToClient(int clientSocket, const char* message);
void broadcast_Message(const Client* clients, int numClients, const char* message);
void handle_Request(Client* client, const Client* clients, int numClients, const char* request, const Map* map);
void handleClient_Requests(Client* client, const Client* clients, int numClients, const Map* map);
void accept_Clients(int serverSocket, Client* clients, int* numClients, const Map* map);
void executeServer(int port, const Map* map);
void initialize_Map(const char* mapFile, Map* map);
int main(int ac, char* av[]);

#endif /* !SV_FUNCTIONTYPE_H_ */
