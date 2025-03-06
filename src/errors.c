#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/errors.h"

void redirect_errors_to_file(const char *path) {
    // file access checking
    if (access(path, W_OK) == -1) {
        // creating file if not accessible
        FILE *file = fopen(path, "w");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fclose(file);
    }

    //  stderr redirecting
    FILE *file = freopen(path, "a", stderr);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
