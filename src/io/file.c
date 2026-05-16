#include <stdio.h>
#include "Editor.h"
#include "file.h"

void loadFile(char* filename){
    FILE *fd;
    char *data;
    
    if(!(fd = fopen(filename, "rw"))){
		fprintf(stderr, "\"%s\" no such file or directory\n", filename);
		return;
	}

    while (!feof(fd)){
        getline(&data, 0, fd);
        insertRow(data);
    }
    return;
}