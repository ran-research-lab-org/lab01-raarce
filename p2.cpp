// Tu nombre de usuario
// Programa Hello World para ncurses
#include <ncurses.h>
int main()
{
    // Initialize the ncurses library
    initscr();
    start_color();

    // Define color pairs
    init_pair(1, COLOR_WHITE, COLOR_GREEN);    // White text on green background
    init_pair(2, COLOR_WHITE, COLOR_BLUE);     // White text on blue background
    init_pair(3, COLOR_WHITE, COLOR_RED);      // White text on red background
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);  // White text on magenta background

    attron(COLOR_PAIR(1));                            // Activate the color pair 1
    mvprintw(0, 0, "++++++++");  // Display some string
    attroff(COLOR_PAIR(1));                           // Deactivate the color pair 1
    attron(COLOR_PAIR(2));                            // Activate the color pair 1
    mvprintw(1, 0, "oooooooo");  // Display some string
    attroff(COLOR_PAIR(2));                           // Deactivate the color pair 1
    attron(COLOR_PAIR(3));                            // Activate the color pair 1
    mvprintw(0, 8, "@@@@@@@@");  // Display some string
    attroff(COLOR_PAIR(3));                           // Deactivate the color pair 1
    attron(COLOR_PAIR(4));                            // Activate the color pair 1
    mvprintw(1, 8, "$$$$$$$$");  // Display some string
    attroff(COLOR_PAIR(4));                           // Deactivate the color pair 1


    refresh(); // Refresh the screen to show the changes
    getch();   // Wait for a user input to exit
    endwin();  // End ncurses mode and clean up

    return 0;
}
