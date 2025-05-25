#include <stddef.h>
#include <string.h>
#include <stdio.h>

int main() {
    char name[50];

    printf("What is your name? - ");
    if (fgets(name, sizeof(name), stdin)) {
        size_t len = strlen(name);
        if (len > 0 && name[len-1] == '\n') {
            name[len-1] = '\0';
        }
    }

    printf("Hello, %s!\n", name);

    return 0;
}
