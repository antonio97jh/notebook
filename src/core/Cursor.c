#include "Cursor.h"


void move_cursor_left(Cursor *cursor){
	if(cursor->column > 0){
		cursor->column--;
	}
	return;
}
void move_cursor_right(Cursor *cursor, unsigned row_length){
	if(cursor->column < row_length){
		cursor->column++;
	}
	return;
}
void move_cursor_up(Cursor *cursor){
	if(cursor->row > 0){
		cursor->row--;
	}
	return;
}
void move_cursor_down(Cursor *cursor, unsigned num_rows){
	if(cursor->row < num_rows){
		cursor->column++;
	}
	return;
}