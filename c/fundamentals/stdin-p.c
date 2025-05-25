#include <stdio.h>    // Standard Input/Output library: defines FILE, stdin, printf, fgets, etc.
#include <stdlib.h>   // Standard library: defines exit codes and functions like malloc/free (not used here but good habit).

// argc is the number of arguments passed in
// argv is an array of strings representing those arguments
int main(int argc, char* argv[])
{
    FILE* input = NULL;   // FILE* is a pointer to a file object; can represent both files and standard streams (like stdin).

    if (argc > 1) {       // If there is a command-line argument (argc > 1), assume it's a filename.
        input = fopen(argv[1], "r");   // fopen opens a file for reading ("r" = read mode). Returns NULL if it fails.
        if (!input) {     // Always check if fopen succeeded. If it fails, input is NULL.
            perror("Error opening the file"); // perror prints a human-readable error message for the last system error.
            return 1;     // Return a nonzero exit code to indicate failure (conventional in Unix-like systems).
        }
    } else {              // If no filename was provided,
        input = stdin;    // stdin is the standard input FILE*. You do NOT need to open or close it.
    }

    char line[1024];      // Declares a buffer to hold a line of text (max 1023 chars + null terminator). 
                          // If a line is longer, fgets will only read up to sizeof(line) - 1 chars per call.
    while (fgets(line, sizeof(line), input)) { 
        // fgets reads a line from input (file or stdin), stores it in 'line'.
        // Returns NULL on EOF or error. 
        // The buffer will include the newline character if present.
        printf("Read line %s", line);  // Prints each line as read. 
                                       // Note: 'line' already contains the newline char if present, so no need to add '\n'.
    }

    if (input != stdin) { // Only close the file if we opened it; never close stdin!
        fclose(input);    // fclose closes a file pointer, releasing associated resources.
    }

    return 0; // Return 0 to indicate successful execution.
}
