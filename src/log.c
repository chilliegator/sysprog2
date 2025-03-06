#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/log.h"

void redirect_output_to_file(const char *path) {
    // file access checking
    if (access(path, W_OK) == -1) {
        // creating if not accessible
        FILE *file = fopen(path, "w");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fclose(file);
    }

    // stdout redirecting
    FILE *file = freopen(path, "a", stdout);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
