// Tu nombre
// Animación básica usando ncurses

#include <ncurses.h>
#include <unistd.h>
#include <cmath>
#include <ctime>
using namespace std;
// Función que dibuja un rectángulo de color usando el caracter c con esquina superior
// izquierda en startRow y startCol y dimensiones height y width

void draw_rectangle(int startRow, int startCol, int height, int width, int color, char c)
{
    attron(COLOR_PAIR(color));
    for (int i = startRow; i <= startRow + height; i++)
        mvhline(i, startCol, c, width); // Top line
    attroff(COLOR_PAIR(color));
}



bool isBetween(int a, int b, int val) {
    if (a > b) {int tmp = a; a = b; b = tmp;}
    return (val >= a && val <= b);
}
void draw_line(int x0, int y0, int x1, int y1, int color, char c)
{
    // compute m
    int deltax = x1 - x0;
    int deltay = y1 - y0;
    
    // float m = (static_cast<float>(y1)-y0)/ (x1-x0);

    attron(COLOR_PAIR(color));
    if (deltax == 0) mvvline( y0 < y1 ? y0:y1, x1, c, abs(deltay));
    else if (deltay == 0) mvhline(  y1, x0 < x1 ? x0:x1, c, abs(deltax));
    else {
        // int tmpy = y0;
        //draw_line(20,5,10,10,2,'o');
        float m = (static_cast<float>(y1)-y0)/ (x1-x0);
        int ctr = 0;
        int firstX = x0 < x1 ? x0 : x1;
        int lastX = x0 < x1 ? x1 : x0;
        int firstY = x0 < x1 ? y0 : y1;
        int lastY = x0 > x1 ? y0 : y1;
        
        // m = x0 < x1 ? m : -m;
        for(int x = firstX; x <= lastX; x = x + 1) {
            int tmpY = round(firstY + (x-firstX)*m);
            if (isBetween(y0, y1, tmpY))
                mvvline(tmpY, x, c, 1);
            
        }

        firstY = y0 < y1 ? y0 : y1;
        lastY = y0 < y1 ? y1 : y0;
        firstX = y0 < y1 ? x0 : x1;
        lastX = y0 < y1 ? x1 : x0;

        for(int y = firstY; y <= lastY; y =y + 1) {
            int tmpX = round(firstX + (y-firstY)* (1/m));
            if (isBetween(x0, x1, tmpX))
                mvvline(y, tmpX, c, 1);
            
        }


    }
    // for (int i = startRow; i <= startRow + height; i++)
    //     mvhline(i, startCol, c, width); // Top line
    attroff(COLOR_PAIR(color));
}


void draw_circle(int x, int y, int r, int color, char c)
{
    int prevX = r + x, prevY =  y;
    attron(COLOR_PAIR(color));
    for (float t = 0; t <= 6.28 ; t+=6.28/360) {
        int thisX = round(r*cos(t) + x);
        int thisY = round(r*sin(t) + y);
// mvhline( thisY,thisX, c, 1); 
        // if (thisX == prevX && thisY == prevY )
            
        // else {
            draw_line(thisX, thisY, prevX, prevY, color,c);

        // }

            prevX = thisX; 
            prevY = thisY;
    }
    attroff(COLOR_PAIR(color));
}

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, int color, char c) {
    draw_line(x0, y0, x1, y1, color, c);
    draw_line(x1, y1, x2, y2, color, c);
    draw_line(x2, y2, x0, y0, color, c);
}

int min(int a, int b) { return a < b ? a : b;}
int max(int a, int b) { return a > b ? a : b;}


int main()
{
    srand(time(NULL));
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
    // timeout(0);

    float x = 0;
    int y = 0;
    int tmpColor = 0;
    int r = 1;
    // lo siguiente es un loop infinito que en cada vuelta actualiza
    // la posición en la que se dibuja el rectangulo
    while (1)
    {
        clear();
        // draw_line(0, 0, 0, LINES-1,  2, ' ');
        // draw_line(0, LINES-1, COLS-1, LINES-1,  2, ' ');
        // draw_line(COLS-1, LINES-1, COLS-1, 0,   2, ' ');
        // draw_line(COLS-1, 0, 0, 0,   2, ' ');

        // // draw_line(1, 3, 7, 3, 3, 'X');
        // draw_line(0, 0, COLS-1, LINES-1, 3, '@');
        // draw_line(0, LINES-1, COLS-1, 0, 3, '@');

        // draw_triangle(10,10, 30,22, 25, 8, 2, 'Y');
        int x0 = rand() % COLS , y0 = rand() % LINES;
        int x1 = rand() % COLS , y1 = rand() % LINES;
        int x2 = rand() % COLS , y2 = rand() % LINES;

        draw_triangle(x0, y0, x1, y1, x2, y2, 2, 'R');

        draw_circle(COLS/2,LINES/2,r = (r + 1) % (LINES/2),tmpColor = (tmpColor + 1) % 4 + 1,'c');
        
        int minX = min(x0, min(x1,x2));
        int minY = min(y0, min(y1,y2));
        int maxX = max(x0, max(x1,x2));
        int maxY = max(y0, max(y1,y2));

        // draw_line(minX, minY,minX, maxY, 4, 'e');
        // draw_line(minX, minY,maxX, minY, 4, 'e');
        // draw_line(maxX, minY,maxX, maxY, 4, 'e');
        // draw_line(minX, maxY,maxX, maxY, 4, 'e');

        refresh();
        x = (x + .05) ;
        y = (y + 1) % LINES;
        usleep(10000);
        
         getch();
    }
    
    getch();  // Wait for a user input to exit
    endwin(); // End ncurses mode and clean up

    return 0;
}
