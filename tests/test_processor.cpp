#include <gtest/gtest.h>
#include "data_processor.h"

// Пример теста (студенты должны дописать свои тесты)
TEST(ProcessorTest, EmptyLine) {
    ProcessResult res = process_line("");
    EXPECT_EQ(res.word_count, 0);
    EXPECT_EQ(res.char_count, 0);
    EXPECT_TRUE(res.longest_word.empty());
}

// TODO: добавить тесты для строк с одним словом,
// с несколькими словами, с ведущими/конечными пробелами и т.д.
TEST(ProcessorTest, OneWord) {
    ProcessResult res = process_line("Hello");
    EXPECT_EQ(res.word_count, 1);
    EXPECT_EQ(res.char_count, 5);
    EXPECT_EQ(res.longest_word, "Hello");
}

TEST(ProcessorTest, SomeWord) {
    ProcessResult res = process_line("Hello world C++");
    EXPECT_EQ(res.word_count, 3);
    EXPECT_EQ(res.char_count, 15);
    EXPECT_EQ(res.longest_word, "Hello");
}

TEST(ProcessorTest, FrontSpace) {
    ProcessResult res = process_line(" Cемь раз отмерь один раз отрежь");
    EXPECT_EQ(res.word_count, 6);
    EXPECT_EQ(res.char_count, 32);
    EXPECT_EQ(res.longest_word, "отмерь");
}

TEST(ProcessorTest, BackDoubleSpace) {
    ProcessResult res = process_line("Cемь раз отмерь один раз отрежь  ");
    EXPECT_EQ(res.word_count, 6);
    EXPECT_EQ(res.char_count, 33);
    EXPECT_EQ(res.longest_word, "отмерь");
}