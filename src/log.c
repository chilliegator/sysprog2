#include <stdio.h>
#include <stdlib.h>

// Функция для перенаправления stdout (стандартного вывода) в файл
void redirect_output(const char *path) {
    // Используем freopen для перенаправления stdout в указанный файл
    FILE *file = freopen(path, "w", stdout);
    if (file == NULL) {
        // Если перенаправление не удалось, выводим ошибку и завершаем программу
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
