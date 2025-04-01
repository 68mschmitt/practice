#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    int cols = 5;
    if (argc > 1) {
        cols = atoi(argv[1]);
    }
    int count = 0;
    if (d) {
        while ((dir = readdir(d)) != NULL ) {
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            if (count >= cols && count % cols == 0) {
                printf("\n");
            } else if (count != 0) {
                printf("    ");
            }
            printf("%s", dir->d_name);
            count++;
        }
        printf("\n");
        closedir(d);
    }
    return(0);
}
