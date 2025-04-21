#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Для getopt()
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "errors.h"

// Функция для симуляции ошибки (открытие несуществующего файла)
//void simulate_error() {
//   FILE *file = fopen("Non_existent_file.txt", "r");
//    if (file == NULL) {
        // Если файл не удалось открыть, выводим ошибку в stderr
//        perror("Error: Failed to open file"); // Искусственно созданная ошибка
//    }
//}

int main(int argc, char *argv[]) {
    int opt;
    const char *log_path = NULL;  // Путь для перенаправления stdout
    const char *errors_path = NULL;  // Путь для перенаправления stderr
    int users_flag = 0;  // Флаг для вывода списка пользователей
    int processes_flag = 0;  // Флаг для вывода списка процессов

    // Обработка аргументов командной строки с помощью getopt
    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                users_flag = 1;  // Устанавливаем флаг для вывода пользователей
                break;
            case 'p':
                processes_flag = 1;  // Устанавливаем флаг для вывода процессов
                break;
            case 'h':
                print_help();  // Вывод справки
                return 0;
            case 'l':
                log_path = optarg;  // Сохраняем путь для логов
                break;
            case 'e':
                errors_path = optarg;  // Сохраняем путь для ошибок
                break;
            default:
                // Если аргумент неизвестен, выводим сообщение об ошибке и справку
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return EXIT_FAILURE;
        }
    }

    // Перенаправляем stdout в файл, если указан флаг -l
    if (log_path) {
        redirect_output(log_path);
    }

    // Перенаправляем stderr в файл, если указан флаг -e
    if (errors_path) {
        redirect_errors(errors_path);
    }

    // Симулируем ошибку (открытие несуществующего файла)
//    simulate_error();

    // Выполняем команды в зависимости от флагов
    if (users_flag) {
        print_users();  // Вывод списка пользователей
    }
    if (processes_flag) {
        print_processes();  // Вывод списка процессов
    }

    // Если не было указано ни одной команды, выводим справку
    if (optind == 1 && !users_flag && !processes_flag) {
        print_help();
    }

    return 0;
}
