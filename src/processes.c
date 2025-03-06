#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include "../include/processes.h"

void print_processes_sorted() {
    DIR *dir;
    struct dirent *entry;

    // /proc path
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // reading dir
    while ((entry = readdir(dir)) != NULL) {
        // checking PID
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);  // PID printing
        }
    }

    // closing dir
    closedir(dir);
}
