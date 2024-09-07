// Tu nombre
// Animación básica usando ncurses

#include <ncurses.h>
#include <unistd.h>
#include <cmath>

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

        init_color(COLOR_RED, 1000, 0, 0);  // Darker Red (700 out of 1000)
        init_color(COLOR_BLUE, 0, 0, 1000);  // Darker Red (700 out of 1000)
init_color(COLOR_GREEN, 0, 1000, 0);  // Darker Red (700 out of 1000)
    init_pair(1, COLOR_RED, COLOR_BLACK);  // Red text on black background
    init_pair(2, COLOR_GREEN, COLOR_BLUE); // Green text on black background
    init_pair(3, COLOR_BLUE, COLOR_GREEN); // Blue text on white background
    init_pair(4, COLOR_YELLOW, COLOR_RED); // Blue text on white background

    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);
    timeout(0);

    float x = 0;
    int y = 0;
    // lo siguiente es un loop infinito que en cada vuelta actualiza
    // la posición en la que se dibuja el rectangulo
    while (1)
    {
        clear();
        draw_rectangle(cos(x)*10 + LINES/2, sin(x)*15 + COLS/2, 2, 3, 4, ' ');
        draw_rectangle(cos(x)*15 + LINES/2, sin(x)*25 + COLS/2, 3, 4, 2, ' ');
        draw_rectangle(LINES/2, COLS/2, 2, 3, 3, ' ');

        refresh();
        x = (x + .05) ;
        y = (y + 1) % LINES;
        usleep(10000);
        
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
