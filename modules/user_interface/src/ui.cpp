#include "ui.h"
#include "data_processor.h"
#include "logger.h"
#include <fstream>
#include <iostream>
#include <sstream>

void run_analysis(const std::string& filepath) {
    // TODO: открыть файл, построчно читать,
    // вызывать process_line, логировать результаты
    std::ifstream file;
    file.open(filepath);
    if (!file.is_open()) {
        log_message(LogLevel::ERROR, "Ошибка при открытии файла!");
        return;
    }
    std::string line;
    ProcessResult result;
    std::ostringstream message;
    while (std::getline(file, line)) {
        result = process_line(line);
        message << "Строка: " << line << "\nКол-во слов: " << result.word_count << "\nКол-во символов: " << result.char_count << "\nСамое длинное слово: " << result.longest_word << std::endl;
        log_message(LogLevel::INFO, message.str());
        message.str("");
    }
    log_close();
}