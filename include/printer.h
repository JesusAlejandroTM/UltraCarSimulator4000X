#ifndef PRINTER_H
#define PRINTER_H

#define TOP_ANCHOR_POSITION 0
#define LEFT_ANCHOR_POSITION 0

void clear_screen();
void move_cursor(int x, int y);
void print_map(const char *asset_file_path);
void print_object(const char *asset_file_path, int posX, int posY);

#endif //PRINTER_H