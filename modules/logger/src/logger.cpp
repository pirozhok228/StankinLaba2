#define _CRT_SECURE_NO_WARNINGS
#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

bool isConsole = false;
std::ofstream logFile;

void log_init(const std::string& filename) {
    // TODO: если filename не пуст, открыть файл для записи
    // иначе настроить вывод в консоль
    if (logFile.is_open()) {
        logFile.close();
    }

    if (filename == "") {
        isConsole = true;
        return;
    }
    logFile.open(filename, std::ios::app);
}

void log_close() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

std::string getStrLevel(LogLevel level) {
    std::string strLevel;
    if (level == 0) {
        strLevel = "INFO";
    }
    else if (level == 1) {
        strLevel = "WARNING";
    }
    else {
        strLevel = "ERROR";
    }
    return strLevel;
}

std::string getStrTime() {
    time_t now;
    std::time(&now);
    std::string strTime = ctime(&now);
}

void log_message(LogLevel level, const std::string& message) {
    // TODO: сформировать строку с временной меткой и уровнем,
    // записать в файл или в консоль

    if (isConsole) {
        printf("[%s] Time: %s\n%s", getStrLevel(level), getStrTime(), message);
    }
    else {
        logFile <<"[" << getStrLevel(level) << "]" << " Time: " << getStrTime() << "\n" << message << "\n";
        //logFile.close();
    }
}