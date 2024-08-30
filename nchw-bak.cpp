#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <cstdlib>

void draw_rectangle(int start_row, int start_col, int height, int width, int color, char c)
{
    attron(COLOR_PAIR(color));
    for (int i = start_row; i <= start_row + height; i++)
        mvhline(i, start_col, c, width); // Top line
    attroff(COLOR_PAIR(color));
}


int main()

{
    // Initialize the ncurses library
    initscr();

    start_color();

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);   // Red text on black background
    init_pair(2, COLOR_GREEN, COLOR_BLUE); // Green text on black background
    init_pair(3, COLOR_BLUE, COLOR_WHITE);  // Blue text on white background
    init_pair(4, COLOR_YELLOW, COLOR_RED);  // Blue text on white background

    // Print "Hello, World!" in the middle of the screen
    mvprintw(0, (COLS - 5) / 2, "Norte");

    mvprintw(LINES / 2, (COLS - 1) / 2, "+");
    mvprintw(LINES / 2, 0, "Oeste");
    mvprintw(LINES / 2, (COLS - 4), "Este");
    mvprintw(LINES - 1, (COLS - 3) / 2, "Sur");
    // mvprintw(LINES / 2, (COLS - 11) / 2, "Hello, World!");
    mvhline(5, 10, '+', 40);
    curs_set(0);
    // Hide the cursor
    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);
    timeout(0);


    int i = 0;
    while (1)
    {

        clear();
        draw_rectangle(0, 0, LINES / 2, COLS / 2, i % 4 + 1, ' ');
        draw_rectangle(0, COLS / 2, LINES / 2, COLS / 2, (i + 1) % 4 + 1, ' ');

        draw_rectangle(LINES / 2, COLS / 2, LINES / 2, COLS / 2, (i + 2) % 4 + 1, ' ');
        draw_rectangle(LINES / 2, 0, LINES / 2, COLS / 2, (i +3)% 4 + 1, ' ');

        i = i + 1;

        
        usleep(500000);
        refresh();
    }
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}

