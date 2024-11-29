#include <cstdio>

int strcompare(const void *a, const void *b);
size_t count_fsize(const char *fname);
size_t preprocess(char *input);
void fill_string_array(char *buf, size_t str_count, char **text);
void print_text(char **text);