/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** all_map_gestion
*/

#include "../include/sv_functiontype.h"
#include <stdio.h>

void init(const char* File, Map* map)
{
    FILE* Fileptr = fopen(File, "r");
    if (File == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    fscanf(Fileptr, "%f %d %d ", &map->gravity, &map->width, &map->height);
    map->cells = (char*)malloc(map->width * map->height * sizeof(char));
    fread(map->cells, sizeof(char), map->width * map->height, Fileptr);
    fclose(Fileptr);
}
