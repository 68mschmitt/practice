#include <stdio.h>
#include "count_lines.h"

int count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1; // Error opening file

    int lines = 0;
    char buffer[1024]; // Adjust size as needed

    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }

    fclose(file);
    return lines;
}
