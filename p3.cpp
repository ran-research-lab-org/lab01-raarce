// Tu nombre
// Animación básica usando ncurses

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
    init_pair(3, COLOR_BLUE, COLOR_WHITE); // Blue text on white background
    init_pair(4, COLOR_YELLOW, COLOR_RED); // Blue text on white background

    curs_set(0);
    // Enable keypad input and non-blocking input
    keypad(stdscr, TRUE);
    timeout(0);

    int x = 0;
    int y = 0;
    // lo siguiente es un loop infinito que en cada vuelta actualiza
    // la posición en la que se dibuja el rectangulo
    while (1)
    {
        clear();
        draw_rectangle(10, x, 2, 3, 2, ' ');
        draw_rectangle(y, 10, 2, 3, 3, ' ');
        refresh();
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
        usleep(50000);
        
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
