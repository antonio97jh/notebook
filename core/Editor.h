#include <stdlib.h>

typedef struct row
{
    char *data;
    size_t length;
    struct Row *next;
} Row;

typedef struct textBuffer
{
    int num_rows;
    Row *first_row;
    Row *last_row;
} TextBuffer;

void insertRow(char *data);