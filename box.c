#include <ncurses.h>

int main() {
    int ch;
    int y = 1, x = 1;  // posición inicial dentro de la ventana
    int win_h = 10, win_w = 30;
    int win_y = (LINES - win_h) / 2;
    int win_x = (COLS - win_w) / 2;

    // Inicializar ncurses
    initscr();
    cbreak();
    noecho();

    // Crear ventana centrada
    WINDOW *win = newwin(win_h, win_w, win_y, win_x);
    box(win, '|', '-');
    //keypad(win, TRUE);
    wrefresh(win);

    // Bucle principal
    while ((ch = wgetch(win)) != 'q') {
        // Mover el texto según flechas
        switch(ch) {
            case KEY_UP:
                if (y > 1) y--;
                break;
            case KEY_DOWN:
                if (y < win_h - 2) y++;
                break;
            case KEY_LEFT:
                if (x > 1) x--;
                break;
            case KEY_RIGHT:
                if (x < win_w - 2) x++;
		break;
	}
	// Dibujar el texto en la posición actual
        mvwprintw(win, y, x, "O");
        wrefresh(win);
    }
    delwin(win);
    endwin();
    return 0;
}

