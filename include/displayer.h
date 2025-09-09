#ifndef DISPLAYER_H
#define DISPLAYER_H

void display_map(const char *asset_file_path);
void display_object(const char *asset_file_path, int posX, int posY);
void gotoxy(int x,int y);

#endif //DISPLAYER_H