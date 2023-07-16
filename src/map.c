/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** all_map_gestion
*/

#include "../include/sv_functiontype.h"
#include <stdio.h>

void initialize_Map(const char* mapFile, Map* map)
{
    FILE* mapFilePtr = fopen(mapFile, "r");
    if (mapFile == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    fscanf(mapFilePtr, "%f %d %d ", &map->gravity, &map->width, &map->height);
    map->cells = (char*)malloc(map->width * map->height * sizeof(char));
    fread(map->cells, sizeof(char), map->width * map->height, mapFilePtr);
    fclose(mapFilePtr);
}
