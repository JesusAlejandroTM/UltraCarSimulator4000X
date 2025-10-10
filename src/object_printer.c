// object_printer.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "object_printer.h"

// Window for intro menu
WINDOW *intro_w = NULL;

// Windows for the simulator GUI
WINDOW *top_sim_w = NULL;
WINDOW *mid_sim_w = NULL;
WINDOW *bot_sim_w = NULL;

void print_gui_element(const char *asset_file_path, int x, int y)
{
    if (!asset_file_path) return;

    int start_x = LEFT_SIMULATOR_ANCHOR_POSITION + x;
    int start_y = TOP_SIMULATOR_ANCHOR_POSITION + y;

    char *path = format_file_path(asset_file_path);
    char *objects = format_map_objects_file_path(asset_file_path);

    int cur_y = start_y;
    int cur_x = start_x;

    // Open the file
    FILE *file = fopen(path, "r");
    
    // Print the file
    if (file)
    {
        int c;
        while ((c = getc(file)) != EOF)
        {
            if (c == '\n') {
                // move to next line, reset X to starting column
                cur_y++;
                cur_x = start_x;
                continue;
            }
            mvaddch(cur_y, cur_x++, c);
        }
        fclose(file);
    }
    refresh();
    free(path);
}

// Print a map to the simulator screen
void print_map(WINDOW* win, const char *asset_file_path)
{
    if (!win && !asset_file_path) return;

    int start_x = LEFT_SIMULATOR_ANCHOR_POSITION;
    int start_y = TOP_SIMULATOR_ANCHOR_POSITION;

    char *path = format_file_path(asset_file_path);
    char *objects = format_map_objects_file_path(asset_file_path);

    int cur_y = start_y;
    int cur_x = start_x;

    // Open the file
    FILE *file = fopen(path, "r");
    
    // Print the file
    if (file)
    {
        int c;
        while ((c = getc(file)) != EOF)
        {
            if (c == '\n') {
                // move to next line, reset X to starting column
                cur_y++;
                cur_x = start_x;
                continue;
            }
            mvwaddch(win, cur_y, cur_x++, c);
        }
        fclose(file);
    }
    wrefresh(mid_sim_w);
    free(path);
}

// Print a map object to the simulator screen
void print_map_object(WINDOW* win, const MapObject* obj)
{
    if (!win && !obj) return;
    
    char *asset_file_path = get_object_asset_name(*obj);
    Point position = map_object_get_position(obj);

    int start_x = LEFT_SIMULATOR_ANCHOR_POSITION + position.x;
    int start_y = LEFT_SIMULATOR_ANCHOR_POSITION + position.y;

    char *path = format_file_path(asset_file_path);

    int cur_x = start_x; 
    int cur_y = start_y;

    // Open the file
    FILE *file = fopen(path, "r");

    // Print the file
    if (file)
    {
        int c;
        while ((c = getc(file)) != EOF)
        {
            if (c == '\n') {
                // move to next line, reset X to starting column
                cur_y++;
                cur_x = start_x;
                continue;
            }
            mvwaddch(win, cur_y, cur_x++, c);
        }
        fclose(file);
    }
    wrefresh(mid_sim_w);
    free(path);
}




