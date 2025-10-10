// object_printer.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#include "object_printer.h"

// Window for intro menu
WINDOW *intro_w = NULL;

// Windows for the simulator GUI
WINDOW *top_sim_w = NULL;
WINDOW *mid_sim_w = NULL;
WINDOW *bot_sim_w = NULL;

// Helpte
static void write_ascii_file(
    WINDOW *win,
    const char *path,
    int start_x,
    int start_y,
    int replacement_char /* pass -1 to keep original chars */
) {
    if (!win || !path) return;

    FILE *file = fopen(path, "r");
    if (!file) return;

    int cur_y = start_y;
    int cur_x = start_x;

    int c;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            cur_y++;
            cur_x = start_x;
            continue;
        }
        if (replacement_char >= 0) {
            mvwaddch(win, cur_y, cur_x++, replacement_char);
        } else {
            mvwaddch(win, cur_y, cur_x++, c);
        }
    }

    fclose(file);
    wrefresh(win);
}

void print_gui_element(const char *asset_file_path, int x, int y)
{
    if (!asset_file_path) return;

    const int start_x = LEFT_SIMULATOR_ANCHOR_POSITION + x;
    const int start_y = TOP_SIMULATOR_ANCHOR_POSITION  + y;

    char *path = format_file_path(asset_file_path);  // assumed heap-alloc by your utility
    if (!path) return;

    // GUI elements appear on stdscr in your original code
    // If you want a specific window, switch to that window and call mvwaddch.
    FILE *file = fopen(path, "r");
    if (file) {
        int cur_y = start_y, cur_x = start_x, c;
        while ((c = getc(file)) != EOF) {
            if (c == '\n') {
                cur_y++;
                cur_x = start_x;
                continue;
            }
            mvaddch(cur_y, cur_x++, c);
        }
        fclose(file);
        refresh();
    }

    free(path);
}

void print_map(WINDOW* win, const char *asset_file_path)
{
    if (!win || !asset_file_path) return;

    const int start_x = LEFT_SIMULATOR_ANCHOR_POSITION;
    const int start_y = TOP_SIMULATOR_ANCHOR_POSITION;

    char *path = format_file_path(asset_file_path);
    if (!path) return;

    write_ascii_file(win, path, start_x, start_y, -1);

    free(path);
}

void print_map_object(WINDOW* win, const MapObject* obj)
{
    if (!win || !obj) return;

    char *asset_file_path = get_object_asset_name(*obj); 
    if (!asset_file_path) return;

    Point position = map_object_get_position(obj);

    const int start_x = LEFT_SIMULATOR_ANCHOR_POSITION + position.x;
    const int start_y = TOP_SIMULATOR_ANCHOR_POSITION  + position.y;

    char *path = format_file_path(asset_file_path);
    if (path) {
        write_ascii_file(win, path, start_x, start_y, -1);
        free(path);
    }
}

void delete_map_object(WINDOW* win, const MapObject* obj)
{
    if (!win || !obj) return;

    char *asset_file_path = get_object_asset_name(*obj);
    if (!asset_file_path) return;

    Point position = map_object_get_position(obj);

    const int start_x = LEFT_SIMULATOR_ANCHOR_POSITION + position.x;
    const int start_y = TOP_SIMULATOR_ANCHOR_POSITION  + position.y;

    char *path = format_file_path(asset_file_path);
    if (path) {
        // overwrite each char with space
        write_ascii_file(win, path, start_x, start_y, ' ');
        free(path);
    }
}
