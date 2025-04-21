#include <stdio.h>
#include <stdlib.h>

// Функция для перенаправления stderr (стандартного вывода ошибок) в файл
void redirect_errors(const char *path) {
    // Используем freopen для перенаправления stderr в указанный файл
    FILE *file = freopen(path, "w", stderr);
    if (file == NULL) {
        // Если перенаправление не удалось, выводим ошибку и завершаем программу
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
