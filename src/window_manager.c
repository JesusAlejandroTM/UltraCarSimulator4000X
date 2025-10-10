#include <string.h>
#include "window_manager.h"

extern WINDOW *top_sim_w;
extern WINDOW *mid_sim_w;
extern WINDOW *bot_sim_w;

int check_terminal_size()
{
    return (COLS > 150 && LINES > 35);
}

void init_introduction()
{
    box(stdscr, ACS_VLINE, ACS_HLINE);
    
    print_gui_element("/gui/game_title", (COLS - 119) / 2, (LINES - 13) / 4);

    char *play_msg = "PRESS Q TO START!";
    mvprintw((COLS, strlen(play_msg)) / 2, LINES - (LINES / 4), play_msg);
    refresh();
} 

void init_simulator_gui()
{
    // Window sizes for each sub-window
    int top_y_size = 3;
    int bot_y_size = 5;
    int mid_y_size = LINES - top_y_size - bot_y_size;

    // Create sub-windows
    top_sim_w = subwin(stdscr, top_y_size, COLS, 0, 0);
    mid_sim_w = subwin(stdscr, mid_y_size, COLS, top_y_size, 0);
    bot_sim_w = subwin(stdscr, bot_y_size, COLS, top_y_size + mid_y_size, 0);

    // Draw borders
    box(top_sim_w, ACS_VLINE, ACS_HLINE);
    box(mid_sim_w, ACS_VLINE, ACS_HLINE);
    box(bot_sim_w, ACS_VLINE, ACS_HLINE);

    // Print inside title and menu bar
    char *title = "Ultra Car Simulator 4000 X";
    char *menu = "Menu bar";
    mvwprintw(top_sim_w, 1, (COLS - strlen(title)) / 2, "%s", title);
    mvwprintw(bot_sim_w, 2, (COLS - strlen(menu)) / 2, "%s", menu);

    // Refresh windows
    wrefresh(top_sim_w);
    wrefresh(mid_sim_w);
    wrefresh(bot_sim_w);
}

// Print a warning text if the terminal is too small
void init_warning()
{
    box(stdscr, ACS_VLINE, ACS_HLINE);

    char *msg1 = "THE SIMULATOR REQUIRES A BIGGER TERMINAL SIZE";
    char *msg2 = "PLEASE RESIZE YOUR TERMINAL AT FULLSCREEN THEN RESTART THE GAME";
    char *msg3 = "PRESS ANY KEY TO QUIT";

    mvprintw(LINES / 2 - 1, (COLS - strlen(msg1)) / 2, "%s", msg1);
    mvprintw(LINES / 2, (COLS - strlen(msg2)) / 2, "%s", msg2);
    mvprintw(LINES / 2 + 1, (COLS - strlen(msg3)) / 2, "%s", msg3);

    refresh();
}