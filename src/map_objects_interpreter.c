// map_objects_interpreter.c

// Interpretate the [map]_objects.txt file to build
// an array of ObjectAssets which will be printed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_objects_interpreter.h"

#define MAX_SIZE 30 
#define BUFFER_SIZE 12
#define POSITION_ARRAY_SIZE 2

// A single line corresponds to a single object so 
// we can handle ach object separetely per line
char *extract_object_at_line(FILE *objects_file, int line)
{
    if (!objects_file)
    {
        printf("ERROR WHEN GETTING FILE");
        return NULL;
    }
    
    int c;
    int index = 0;
    int line_counter = 0;
    char *buffer = (char *) malloc(sizeof(char) * MAX_SIZE);
    while ((c = getc(objects_file)) != EOF)
    {
        if (c == 10 && line == line_counter)
        {
            return buffer; 
        }
        if (line == line_counter)
        {
	    buffer[index++] = (char) c;
	    buffer[index] = '\0';
        }
        if (c == 10)
        {
            line_counter++;
        }
    } 
}

// Get position from line
int * extract_position_from_line(char *line)
{
    // Buffer to load string of an integer which will be converted to int
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    // Array of length 2 with X and Y position
    int *position_array = malloc(sizeof(int) * POSITION_ARRAY_SIZE);

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == ',')
        {
            position_array[0] = atoi(buffer);
            break;
        }
        
        buffer[buffer_index++] = line[i];
        buffer[buffer_index] = '\0';
       
        // Ignore the object name and clear buffer
        if (line[i] == ';')
        {
            buffer[0] = '\0';
            buffer_index = 0;
        }
    }

    buffer_index = 0;

    for (int i = 0; i < strlen(line) + 1; i++)
    {
        if (line[i] == '\0')
        {
            position_array[1] = atoi(buffer);
            return position_array;
        }

        buffer[buffer_index++] = line[i];
        buffer[buffer_index] = '\0';
        
        if (line[i] == ';' || line[i] == ',')
        {
             buffer[0] = '\0';
             buffer_index = 0;
        }
       
    }
}


// Get object from line 
// Object* extract_object_from_line(char *line)
// {
// 	return Object;
// }


// We have to implement structures inheritance so we can
// handle all sorts of object types and return the object "class"
// Then we return a linked list of each map object.
// The displayer then iterates over the linked list to display each object
// based on the object necessary parameters which are defined by it's class.
void read_map_objects(char *map_asset_name)
{
    char *map_objects_file_path = format_map_objects_file_path(map_asset_name);
    FILE *file = fopen(map_objects_file_path, "r");

    int line = 2;
    char *line_string = extract_object_at_line(file, 2);
    int *position_array = extract_position_from_line(line_string); 
    printf("THE STRING IS : %s", line_string);
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


