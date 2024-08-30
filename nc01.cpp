#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <curses.h>
using namespace std;

int main()
{
  // Initialize ncurses
  WINDOW *W = initscr();  
  cbreak();
  noecho(); 
  nodelay(W,true);

  wmove(W,0,0);
  waddch(W,'$');
  wrefresh(W);
  usleep(800000);

  wmove(W,20,30);
  waddch(W,'2');
  wrefresh(W);
  usleep(800000);

  wmove(W,15,50);
  waddch(W,'3');
  wrefresh(W);

  // Loop forever until user enters 'q'
  char c;
  while((c = wgetch(W)) && c != 'q') {
    usleep(800000);
    if (c > 'a' && c < 'z') {
    wmove(W,rand()%40,rand()%40);
    waddch(W,c);
    wrefresh(W);
    }
  }

  // Clean up after ncurses
  endwin();
  return 0;
}