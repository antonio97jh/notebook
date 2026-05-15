#include "Editor.h"

Editor *editor;

void initializeEditor(){
	TextBuffer *textBuff;
	Cursor *cursor;
	/*Row *row;

	row = (Row*) malloc(sizeof(Row));
	row->data = "\0";
	row->length = 0;
	row->next = NULL;*/

	textBuff = (TextBuffer*) malloc(sizeof(TextBuffer));
	textBuff->num_rows = 0;
	textBuff->first_row = NULL;
	textBuff->last_row = NULL;

	cursor = (Cursor*) malloc(sizeof(Cursor));
	cursor->column = 0;
	cursor->row = 0;
	
	editor = (struct editor*) malloc(sizeof(editor));
	editor->text = textBuff;
	editor->cursor = cursor;

	return;
}

void insertRow(char *data){
    Row *auxRow;
    TextBuffer *text = editor->text;

    auxRow = (Row*) malloc(sizeof(Row));
    auxRow->data = data;
    auxRow->length = strlen(data);
    auxRow->next = NULL;

    if(!text->first_row){
        text->first_row = auxRow;
        text->last_row = auxRow;
    } else {
        text->last_row->next = auxRow;
        text->last_row = auxRow;
    }
    return;    
}

void move_cursor_left(){
	if(editor->cursor->column > 0){
		editor->cursor->column--;
	}
	return;
}
void move_cursor_right(unsigned row_length){
	if(editor->cursor->column < row_length){
		editor->cursor->column++;
	}
	return;
}
void move_cursor_up(){
	if(editor->cursor->row > 0){
		editor->cursor->row--;
	}
	return;
}
void move_cursor_down(){
	if(editor->cursor->row < editor->text->num_rows){
		editor->cursor->column++;
	}
	return;
}

