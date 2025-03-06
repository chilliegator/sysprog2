#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include "../include/users.h"

void print_users_sorted() {
    struct passwd *pw;

    // opening users
    setpwent();

    while ((pw = getpwent()) != NULL) {
        printf("%s: %s\n", pw->pw_name, pw->pw_dir);  // printing name and home path
    }

    // closing db
    endpwent();
}
