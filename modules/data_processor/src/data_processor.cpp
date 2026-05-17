#include "data_processor.h"
#include <string>
#include <iostream>

int utf8_length(const std::string& s) {
    int count = 0;
    for (unsigned char c : s)
        if ((c & 0xC0) != 0x80)
            ++count;
    return count;
}

ProcessResult process_line(const std::string& line) {
    int wordCount = 0;
    int charCount = 0;
    
    std::string currentWord;
    std::string longestWord;
    int maxWordLen = 0;
    
    for (size_t i = 0; i < line.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(line[i]);
        
        if ((c & 0xC0) != 0x80) {
            ++charCount;
        }
        
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            if (!currentWord.empty()) {
                ++wordCount;
                
                int len = utf8_length(currentWord);
                if (len > maxWordLen) {
                    maxWordLen = len;
                    longestWord = currentWord;
                }
                
                currentWord.clear();
            }
        }
        else {
            currentWord += line[i];
        }
    }
    
    if (!currentWord.empty()) {
        ++wordCount;
        int len = utf8_length(currentWord);
        if (len > maxWordLen) {
            longestWord = currentWord;
        }
    }
    
    return ProcessResult{wordCount, charCount, longestWord};
}