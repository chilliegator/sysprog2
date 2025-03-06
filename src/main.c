#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/users.h"
#include "../include/processes.h"
#include "../include/log.h"
#include "../include/errors.h"
#include "../include/help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;  // path for stdout redirecting
    char *errors_path = NULL;  // path for stderr redirecting

    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                if (log_path) {
                    redirect_output_to_file(log_path);  // Перенаправляем stdout в файл
                }
                print_users_sorted();  // users list printing
                break;
            case 'p':
                if (log_path) {
                    redirect_output_to_file(log_path);  // stdout redirecting
                }
                print_processes_sorted();  // proccesses list printing
                break;
            case 'h':
                print_help();  // help manual printing
                return 0;
            case 'l':
                log_path = optarg;  //  stdout path saving
                break;
            case 'e':
                errors_path = optarg;  // stderr path saving
                redirect_errors_to_file(errors_path);  // stderr redirecting
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    return 0;
}
