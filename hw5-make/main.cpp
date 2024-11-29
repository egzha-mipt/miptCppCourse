#include <cassert>
#include "lib.h"

int main() 
{
    // 1) прочитать размер файла
    size_t file_size = count_fsize("onegin.txt");
    // 2) выделить память под буфер
    char *text_buf = (char *)calloc(1, file_size);
    // 3) скопировать файл с диска в буффер в оперативной памяти
    FILE *input = fopen("onegin.txt", "rb");
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
    return 0;
}