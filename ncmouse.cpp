#include <ncurses.h>

int main() {
    MEVENT event;
    
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    
    // Print instructions
    printw("Click inside the window to interact with the mouse.\n");
    printw("Press 'q' to quit.\n");
    refresh();
    
    // Enable mouse input
    while (1) {
        int ch = getch();
        
        switch (ch) {
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    // Check for mouse event
                    if (event.bstate & BUTTON1_CLICKED) {
                        mvprintw(5, 0, "                                         ", event.y, event.x);
                        mvprintw(5, 0, "Mouse clicked at: %d, %d", event.y, event.x);
                        refresh();
                    }
                }
                break;
            case 'q':
                // Exit on 'q' key press
                endwin();
                return 0;
            default:
                break;
        }
    }

    // End ncurses
    endwin();
    return 0;
}