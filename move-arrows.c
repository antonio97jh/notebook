#include <ncurses.h>

int main() {
	int ch = '\0';
	unsigned row = 0;
	unsigned column = 0;
	initscr();            // Inicia ncurses
    	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	while (true){
		clear();
		ch = getch();
		switch(ch) {
			case KEY_UP:
				row = (row-1) >= 0 ? row-1: 0; 
				break;
			case KEY_DOWN:
				row++;
				break;
			case KEY_RIGHT:
				column++;
				break;
			case KEY_LEFT:
				column = (column-1) >= 0 ? column-1: 0;
				break;	
		}
		mvprintw(row, column, "<->");
		refresh();
	}
    endwin();             // Cierra ncurses
    return 0;
}

