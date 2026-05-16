#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "Editor.h"
#include "file.h"

#define FICH "./move-arrows.c"

void spinner_step(WINDOW* win) {
    	static const char spin_chars[] = "|/-\\";
    	static int i = 0;
	
	mvwaddch(win, 1, 1, spin_chars[i]);
    	i = (i + 1) % 4;
}

int main() {
    initscr();
    int ch = 0;
    int h = 40, w = 150;
	int max_x, max_y;
	
	int cy = 0, cx = 0;
	FILE* fd;
	getmaxyx(stdscr, max_y, max_x);
	WINDOW *win = newwin(h, w, (max_y - h)/2, (max_x - w)/2);  // centrada
	box(win, 0, 0);
	raw();
	keypad(win, TRUE);
	nodelay(win, TRUE);
	noecho();
	
	initializeEditor();
	
	loadFile(FICH);

	wmove(win, cy+1, cx+1);
	wrefresh(win);
	
	//editor
	while((ch = wgetch(win)) != 27){
		//spinner_step(win);
		/*if ((ch = wgetch(win)) == 'q'){
			break;	
		}
		wrefresh(win);
		usleep(150000);*/

		if (ch == KEY_LEFT && cx > 0) cx--;
        else if (ch == KEY_RIGHT && cx < 255) cx++;
        else if (ch == KEY_UP && cy > 0) cy--;
        else if (ch == KEY_DOWN && cy < 99) cy++;
        else if (ch >= 32 && ch <= 126) {
			//Insert char into textBuffer
           	//text[cy][cx] = ch;
			mvwaddch(win, cy+1, cx+1, ch);
			cx++;
        }
		else if((ch == KEY_BACKSPACE || ch == 127) && cx > 0){
			//Insert char into textbuffer
			//text[cy][--cx]= ' ';
			mvwaddch(win, cy+1, cx+1, ' ');
		}
		wmove(win, cy+1, cx+1);
		wrefresh(win);
	}
	delwin(win);
	endwin();
	return 0;
}

