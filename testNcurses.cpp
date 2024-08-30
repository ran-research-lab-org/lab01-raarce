#include <ncurses.h>
void printTriangle(int startrow, int startcol, int height);
void printRectangle(int startrow, int startcol, int height, int width);

int main()
{
	initscr();
	start_color();

	init_pair(1, 3, 1);
	init_pair(2, 4, 2);
	init_pair(3, 7, 4);

	attrset(COLOR_PAIR(1));
	printTriangle(3, 15, 4);

	attrset(COLOR_PAIR(2));
	printRectangle(8, 10, 7, 10);

	attrset(COLOR_PAIR(3));
	printRectangle(11, 12, 4, 2);

	getch();
	endwin();
	return 0;
}
//----------------------------------------------------------------------------------

void printTriangle(int startrow, int startcol, int height)
{
	int x = startcol;

	for (int r = startrow; r <= startrow + height; r++)
	{
		for (int c = startcol; c <= x; c++)
		{
			move(r, c);
			printw("*");
		}
		x++;
		startcol--;
	}
}

//----------------------------------------------------------------------------------
void printRectangle(int startrow, int startcol, int height, int width)
{
	for (int r = startrow; r <= startrow + height; r++)
	{
		for (int c = startcol; c <= startcol + width; c++)
		{
			move(r, c);
			if (r == startrow || r == startrow + height || c == startcol || c == startcol + width)
				printw("*");
		}
	}
}
