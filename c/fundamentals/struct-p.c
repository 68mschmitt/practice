#include <stdio.h>

// Enum values are, by convention, all uppercase
enum Genre
{
    FANTASY,
    HORROR,
    MYSTERY
};

// the * to designate a variable as a pointer can go after the type or before the var name
// int* myInt
// int *myInt
const char* GenreStrings[] =
{
    "Fantasy",
    "Horror",
    "Mystery"
};

// Property names are, by convention, camel case
struct Book
{
    char* author;
    char* title;
    enum Genre genre;
    int pageCount;
};

int main()
{
    struct Book harryPotter = {"JK Rowling", "Happy Potter and the philosiphers stone", FANTASY, 500};
    printf("Author: %s\nTitle: %s\nGenre: %s\nPage Count: %d\n",
            harryPotter.author,
            harryPotter.title,
            GenreStrings[harryPotter.genre],
            harryPotter.pageCount);

    return 0;
}
