#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE * load_file(char *filepath) {
    FILE *file_ptr = fopen(filepath, "rt");

    if (file_ptr == NULL) {
        printf("File not found >:(\n");
        return NULL;
    }
    return file_ptr;
}

void cleanup(FILE *file_ptr, char *line_buffer) {
    if (line_buffer) free(line_buffer);
    if (file_ptr) fclose(file_ptr);
}

int reader(char *filepath) {
    FILE *file_ptr = load_file(filepath);

    if (file_ptr == NULL) {
        return 1;
    }

    int max_line_length = 256;
    char *line_buffer = malloc(max_line_length);
    if (!line_buffer) {
        perror("malloc");
        fclose(file_ptr);
        return 1;
    }

    while (fgets(line_buffer, max_line_length, file_ptr) != NULL) {
        printf("%s", line_buffer);
    }
    cleanup(file_ptr, line_buffer);
    return 0;
}


