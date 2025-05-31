#include <stdio.h>
#include "count_lines.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <>\n", argv[0]);
        return 1;
    }

    int lines = count_lines(argv[1]);
    printf("Total lines: %d\n", lines);
    return 0;
}
