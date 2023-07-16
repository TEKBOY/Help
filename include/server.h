/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** project_ser_h_type
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef SERVER_H_
    #define SERVER_H_

    #define MAX_CLIENTS 2
    #define BUFFER_SIZE 1024

typedef struct {
    int id;
    int socket;
    int x;
    int y;
    int score;
    int state;
} Client;

typedef struct {
    float gravity;
    int width;
    int height;
    char* cells;
} Map;

#endif /* !SERVER_H_ */
