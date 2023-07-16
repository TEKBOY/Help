/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main_function
*/

#include "../include/sv_functiontype.h"

int main(int ac, char* av[])
{
    if (ac != 7) {
        fprintf(stderr, "Usage: %s -p <port> -g <gravity> -m <map>\n", av[0]);
        return 1;
    }
    int port, gravity; const char* File;
    for (int i = 1; i < ac; i += 2) {
        if (strcmp(av[i], "-p") == 0) {
            port = atoi(av[i + 1]);
        } else if (strcmp(av[i], "-g") == 0) {
            gravity = atoi(av[i + 1]);
        } else if (strcmp(av[i], "-m") == 0) {
            File = av[i + 1];
        } else {
            fprintf(stderr, "Invalid argument: %s\n", av[i]);
            return 1;
        }
    } Map map; init(File, &map);
    execute(port, &map);
    return (0);
}
