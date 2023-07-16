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
void update_Playerposition(Client* client, int newX, int newY, char* cells, int width, int height, const Client* clients, int numclients);
void sendmessage(int clientSocket, const char* message);
void broadcast_Message(const Client* clients, int numclients, const char* message);
void handlerequest(Client* client, const Client* clients, int numclients, const char* request, const Map* map);
void handleclientrequests(Client* client, const Client* clients, int numclients, const Map* map);
void acceptclient(int sockett, Client* clients, int* numclients, const Map* map);
void initialize(int* sockett, int port);
void run(int sockett, const Map* map);
void execute(int port, const Map* map);
void init(const char* File, Map* map);
int main(int ac, char* av[]);

#endif /* !SV_FUNCTIONTYPE_H_ */
