#include "ui.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ".UTF-8");
    log_init("");  // логирование в консоль
    
    std::string path;
    std::cout << "Введите путь к текстовому файлу: ";
    std::getline(std::cin, path);

    if (path.empty()) {
        log_message(ERROR, "Путь не указан");
        return 1;
    }

    run_analysis(path);

    std::cout << "Первый разработчик" << std::endl;

    return 0;
}