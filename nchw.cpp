#include <ncurses.h>
// #include <unistd.h>
// #include <string>
// #include <cstdlib>

// void draw_rectangle(int start_row, int start_col, int height, int width, int color, char c)
// {
//     attron(COLOR_PAIR(color));
//     for (int i = start_row; i <= start_row + height; i++)
//         mvhline(i, start_col, c, width); // Top line
//     attroff(COLOR_PAIR(color));
// }

#include <ncurses.h>
int main()
{
    // Initialize the ncurses library
    initscr();
    start_color();

    // Define color pairs
    init_pair(1, COLOR_WHITE, COLOR_GREEN);   // Red text on black background
    init_pair(2, COLOR_WHITE, COLOR_BLUE);  // White text on black background
    init_pair(3, COLOR_WHITE, COLOR_RED);  // Blue text on white background
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);  // Blue text on white background

    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2, (COLS - 1) / 2, "++++++++");
    attroff(COLOR_PAIR(1));

    refresh(); // Refresh the screen to show the changes
    getch();   // Wait for a user input to exit
    endwin();  // End ncurses mode and clean up

    return 0;
}

