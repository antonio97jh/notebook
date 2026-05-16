#include <stdlib.h>

typedef struct cursor
{
    size_t row;
    size_t column;
} Cursor;

void move_cursor_left(Cursor*);
void move_cursor_right(Cursor*, unsigned);
void move_cursor_up(Cursor*);
void move_cursor_down(Cursor*, unsigned);