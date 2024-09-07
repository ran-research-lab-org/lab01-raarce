// Tu nombre
// Tu descripción aquí

#include <ncurses.h>
#include <unistd.h>

// Función que dibuja un rectángulo de color usando el caracter c con esquina superior
// izquierda en startRow y startCol y dimensiones height y width

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
    init_pair(3, COLOR_BLUE, COLOR_YELLOW); // Blue text on white background
    init_pair(4, COLOR_YELLOW, COLOR_RED); // Blue text on white background

    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);
    timeout(0);
 
    int c = 0;
    while (1)
    {
        clear();
        // upper left
        draw_rectangle(0, 0, LINES/2, COLS/2, (c + 4)%4 + 1, ' ');
        // upper right
        draw_rectangle(0, COLS/2, LINES/2, COLS/2, (c + 3)%4 + 1, ' ');
        // lower right
        draw_rectangle(LINES/2, COLS/2, LINES, COLS, (c + 2)%4 + 1, ' ');
        // lower left
        draw_rectangle(LINES/2, 0, LINES/2, COLS/2, (c + 1)%4 + 1, ' ');
        refresh();
        c = (c + 1) % 4;
        usleep(1000000);
        
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
