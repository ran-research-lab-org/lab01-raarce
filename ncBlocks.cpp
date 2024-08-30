#include <ncurses.h>
#include <unistd.h>

void draw_rectangle(int startRow, int startCol, int height, int width, int color, char c)
{
    attron(COLOR_PAIR(color));
    for (int i = startRow; i <= startRow + height; i++)
        mvhline(i, startCol, c, width); // Top line
    attroff(COLOR_PAIR(color));
}

int main()
{
    initscr();     // Initialize the ncurses library
    start_color();

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);  // Red text on black background
    init_pair(2, COLOR_GREEN, COLOR_BLUE); // Green text on black background
    init_pair(3, COLOR_BLUE, COLOR_WHITE); // Blue text on white background
    init_pair(4, COLOR_YELLOW, COLOR_RED); // Blue text on white background

    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);
    timeout(0);

    int x = 0;
    while (1)
    {
        clear();
        draw_rectangle(10, x, 2, 3, 2, ' ');
        x = (x + 1) % COLS;

        usleep(50000);
        refresh();
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
