#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>  // Для работы с директориями

// Функция для вывода списка процессов
void print_processes() {
    DIR *dir;  // Указатель на директорию
    struct dirent *entry;  // Структура для хранения информации о файле/директории

    // Открываем директорию /proc, где хранится информация о процессах
    dir = opendir("/proc");
    if (dir == NULL) {
        // Если открыть директорию не удалось, выводим ошибку и завершаем функцию
        perror("opendir");
        return;
    }

    // Читаем записи в директории
    while ((entry = readdir(dir)) != NULL) {
        // Проверяем, является ли запись директорией (процессом)
        if (entry->d_type == DT_DIR) {
            // Выводим PID процесса
            printf("Process ID: %s\n", entry->d_name);
        }
    }

    // Закрываем директорию
    closedir(dir);
}
