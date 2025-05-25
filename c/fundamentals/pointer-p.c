#include <stdio.h>

int main()
{
    int myInt = 32;
    int *myP = &myInt;

    printf("My int from a pointer: %d\n", *myP);
    
    return 0;
}
