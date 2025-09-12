// Interpretate the [map]_objects.txt file to build
// an array of ObjectAssets which will be printed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_objects interpreter.h"

#define MAX_SIZE 15

void read_map_objects(char *map_asset_name)
{

}

char *fetch_asset_name(char *map_asset_name, int count)
{
    char *map_objects_file_path = format_map_objects_file_path(map_asset_name);
    // Open the file
    FILE *file = fopen(map_objects_file_path, "r");

    int c;
    char buffer[MAX_SIZE]; 
    
    char asset_name[MAX_SIZE];

    int line = 0;
    int index = 0;

    if (file) 
    {
        while ((c = getc(file)) != EOF)
        {
            // We build the buffer until we find ; with specified line
            if (c !=';')
            {
                buffer[index++] = (char) c;
                buffer[index] = '\0';
            }
            // If ; is found but not at the proper line, clear the buffer
            if (c == ';' && count != line)
            {
                buffer[index] = '\0';
                index = 0;
            }
            // We wish to stop at specified line and build the asset_name
            if (c == ';' && count == line)
            {
                
                size_t size = strlen(buffer);

                char *asset_name = malloc(size + 1);
                strcpy(asset_name, buffer);

                free(map_objects_file_path);
                fclose(file);
                return asset_name;
            }

        }    
        fclose(file);
        return NULL;   
    }
}

