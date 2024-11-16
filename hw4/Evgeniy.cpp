#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdlib> 

int strcompare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}


size_t count_fsize(const char *fname)
{
    FILE *file = fopen(fname, "rb");

    assert(file != nullptr && "проблемы с файлом в count_fsize");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fclose(file);
    return file_size;
}

size_t preprocess(char *input) {
    assert(input != nullptr && "проблемы с указателем в preprocess");

    char *write_ptr = input;
    const char *read_ptr = input;
    size_t full_lines = 0;

    while (*read_ptr != '\0') {
        while (*read_ptr == ' ' || *read_ptr == '\t') {
            ++read_ptr;
        }

        if (*read_ptr == '\0' || *read_ptr == '\n') {
            if (*read_ptr == '\n') {
                ++read_ptr;
            }
            continue;
        }

        ++full_lines;

        bool in_space = false;
        while (*read_ptr != '\0' && *read_ptr != '\n') {
            if (*read_ptr == ' ' || *read_ptr == '\t') {
                if (!in_space) {
                    *write_ptr++ = ' ';
                    in_space = true;
                }
            } else {
                *write_ptr++ = *read_ptr;
                in_space = false;
            }
            ++read_ptr;
        }
        while (write_ptr > input && (*(write_ptr - 1) == ' ')) {
            --write_ptr;
        }
        if (*read_ptr == '\n') {
            *write_ptr++ = '\n';
            ++read_ptr;
        }
    }
    *write_ptr = '\0';
    return full_lines;
}

void fill_string_array(char *buf, size_t str_count, char **text) {
    if ((buf == nullptr) || (text == nullptr)) {
        return;
    }

    size_t index = 0;
    char *line_start = buf;
    while (*line_start != '\0' && index < str_count) {
        char *line_end = strchr(line_start, '\n');
        if (line_end == nullptr) {
            line_end = line_start + strlen(line_start); 
        }

        size_t line_length = line_end - line_start;
        text[index] = new char[line_length + 1];
        strncpy(text[index], line_start, line_length);
        text[index][line_length] = '\0';

        index++;
        line_start = (*line_end == '\n') ? line_end + 1 : line_end;
    }
    text[index] = nullptr;
}

void print_text(char **text) {
    assert(text != nullptr && "проблемы с текстом в print_text");    

    size_t index = 0;
    while (text[index] != nullptr) {
        std::cout << text[index] << std::endl;
        index++;
    }
}


int main()
{
    // 1) прочитать размер файла
    size_t file_size = count_fsize("Onegin.txt");
    // 2) выделить память под буфер
    char *text_buf = (char *)calloc(1, file_size);
    // 3) скопировать файл с диска в буффер в оперативной памяти
    FILE *input = fopen("Onegin.txt", "rb");
    fread(text_buf, 1, file_size, input); // надо погуглить как пользоваться этой функцией
    fclose(input);
    // 4) препроцессинг
    // заменить множество \n подряд на 1 \n, заменить все \n на \0
    size_t str_count = preprocess(text_buf);
    // 5) время заводить массив
    char **text = (char **)calloc(str_count + 1, sizeof(char *));
    // 6) заполняем массив
    fill_string_array(text_buf, str_count, text);
    // 7) сортировать массив с помощью qsort
    qsort(text, str_count, sizeof(char *), strcompare);
    // 8) вывести массив
    print_text(text);
}