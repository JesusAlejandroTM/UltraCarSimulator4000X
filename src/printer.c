#include <stdio.h>
#include <stdlib.h>

#include "map_controller.h"
#include "printer.h"

// Raw function to move cursor
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

// Clean function to move cursor
void move_cursor(int x, int y)
{
    x = LEFT_ANCHOR_POSITION + x;
    y = TOP_ANCHOR_POSITION + y;
    gotoxy(x, y);
}

// Clear the screen and move the cursor to the top-left
void clear_screen()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void print_file(const char *path)
{
    // Open the file
    FILE *file = fopen(path, "r");

    // Print the file
    int c;
    if (file) 
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}

void print_map(const char *asset_file_path)
{
    char *path = format_file_path(asset_file_path);
    char *objects = format_map_objects_file_path(asset_file_path);

    print_file(path);

    free(path);
}

void print_object(const char *asset_file_path, int posX, int posY)
{
    char *path = format_file_path(asset_file_path);
    move_cursor(posX, posY);

    // Open the file
    FILE *file = fopen(path, "r");

    // Print the file
    int c;
    if (file) 
    {
        while ((c = getc(file)) != EOF)
        {
            // If we find a line break, we move the cursor down 
            if (c == '\n') {
                move_cursor(posX, ++posY);
            } else {
                putchar(c);
            }
        }
            
        fclose(file);
    }

    free(path);
}



