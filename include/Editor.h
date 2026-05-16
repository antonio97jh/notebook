#include <stdlib.h>
#include "Cursor.h"
typedef struct Row
{
    char *data;
    size_t length;
    struct Row *next;
} Row;

typedef struct TextBuffer
{
    size_t num_rows;
    Row *first_row;
    Row *last_row;
} TextBuffer;

typedef struct Editor
{
    TextBuffer *text;
    Cursor *cursor;
} Editor;

void initializeEditor(); 
void insertRow(char *);