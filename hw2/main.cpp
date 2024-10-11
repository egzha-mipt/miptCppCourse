#include <iostream>

int main(){
    int varInt1 = 10;
    int varInt2 = 5000;

    char varChar1 = 'E';
    char varChar2 = '^';

    double varDouble1 = 2.7182818284590452353602874713527;
    double varDouble2 = 4750.5000000000000000000000000001;


    std::cout << "1.(int + int) " << "10 + 5000 = " << varInt1 + varInt2 << std::endl; //5010, just sum
    std::cout << "2.(int + char) " << "10 + ^ = " << varInt1 + varChar2 << std::endl; // ^ = 94 due to ASII =>94 + 10 = 104
    // we can use // int num = varChar to find out it's number in ASII code chart
    std::cout << "3.(char + char) " << "E + ^ = " << varChar1 + varChar2 << std::endl; // 94 + 69 = 163
    std::cout << "4.(char + double) "<< "E + 2.71... = " << varChar1 + varDouble1 << std::endl; // 69 + 2.71... = 71.71...
    
    std::cout << "5.(double + double) "<<"2.71... + 4750.50... = " << varDouble1 + varDouble2 << std::endl; // 2.71 + 4750 = 4752.71
    std::cout << "6.(double + int) "<<  "4750.50... + 5000 = " << varDouble2 + varInt2 << std::endl; // 9750.50 because f + i = f; d + i = d
    
    
}
