#include <cstdio>
#include <cstdlib>

int main() {
    //EZ hw part
    char symbol = 'E'; // 1 bite
    int intNumber = 5; // 4 bites
    double e = 2.7182818284590452353602874713527; // 8 bites
    
    char* ptrS = &symbol;
    int* ptrN = &intNumber;

    printf("Address of symbol: %p\nAddress of intNumber: %p\nAddress of  e: %p\n", ptrS, ptrN, &e);
 

    //Evgeniy Onegin
    
    
    
    
    
    return 0;
}
