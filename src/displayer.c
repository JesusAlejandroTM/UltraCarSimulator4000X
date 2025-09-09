#include <stdio.h>
#include <stdlib.h>

#include "map_controller.h"

#include "displayer.h"


void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void print_object(const char *path)
{
    // Open the file
    FILE *file = fopen(path, "r");

    // Print the file
    if (file) {
        char c;
        while ((c = getc(file)) != EOF)
            printf("%c\n", c);
        fclose(file);
    }
}

void display_map(const char *asset_file_path)
{
    char *path = format_file_path(asset_file_path);
    char *objects = format_map_objects_file_path(asset_file_path);

    print_object(path);

    free(path);
}

void display_object(const char *asset_file_path, int posX, int posY)
{
    char *path = format_file_path(asset_file_path);
    gotoxy(posX, posY);
    print_object(path);

    free(path);
}