#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

size_t length(char* str) {
  size_t i = 0;
  while (*(str + i) != 0) {
    i++;
  }
  return i;
}

void stringcopy(char* from, char* to);

int main() {
  std::setlocale(LC_ALL, "Russian");
  char str[128];
  size_t n = 0;
  //FILE* input = fopen("Onegin.txt","r");

  std::ifstream input;
  input.open("C:\\Users\\Arseny\\source\\repos\\ConsoleApp1\\Project2\\Onegin.txt");
  //input >> str;
  //std::cout  << str;
  while (input >> str) {
    std::cout << str<<" "<< length(str) << "\n";
    n++;
  }
  input.clear();
  input.seekg(0);
  int i = 0;
  char** txt = (char**)calloc(n, sizeof(char*));
  while (input >> str) {
    std::cout << str << " " << length(str) << "\n";
    *(txt + i) = (char*)calloc(length(str), sizeof(char));
    stringcopy(str, *(txt + i));
  }
  std::cout << n << "\n";
  for (i = 0; i < n; ++i) {
    std::cout << (txt[i]) << std::endl;
  }
  //stringcopy(nullptr, nullptr);
  std::cout << n << "\n";
  //fclose(input);
  char a = 0;
  //size char*
  //std::cout << ;
}

void stringcopy(char* from, char* to)
{
  size_t i=0;
  while (*(from + i) != 0) {
    *(to + i) = *(from + i);
    i++;
  }
  to[i] = 0;
}
