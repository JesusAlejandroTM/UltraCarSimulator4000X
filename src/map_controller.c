#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map_controller.h"

#define FILE_PATH_PREFIX "assets/"
#define FILE_EXTENSION ".txt"

// Specific for objects inside a map
#define FILE_METADATA_SUFFIX "_objects"

char *format_file_path(const char *asset_file_path)
{
    // Define buffer for file path
    const size_t need = strlen(FILE_PATH_PREFIX) + strlen(asset_file_path) + strlen(FILE_EXTENSION) + 1;

    // Allocate memory for the file path string
    char *path = malloc(need);
    if (!path) perror("malloc");

    // Format the file path
    snprintf(path, need, "%s%s%s", FILE_PATH_PREFIX, asset_file_path, FILE_EXTENSION);

    return path;
}

char *format_map_objects_file_path(const char *asset_file_path)
{
    // Define buffer for file path
    const size_t need = strlen(FILE_PATH_PREFIX) + strlen(asset_file_path) + strlen(FILE_METADATA_SUFFIX) + strlen(FILE_EXTENSION) + 1;

    char *path = malloc(need);
    if (!path) perror("malloc");

    // Format the file path
    snprintf(path, need, "%s%s%s%s", FILE_PATH_PREFIX, asset_file_path, FILE_METADATA_SUFFIX, FILE_EXTENSION);

    return path;
}