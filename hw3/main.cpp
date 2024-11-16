#include <iostream>

int main() {
    int numb = 0;
    uint32_t sum = 0;
    
    while (numb != 5312) {
        std::cout << "Input int number: ";
        std::cin >> numb;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "некорректный формат ввода" << std::endl;
            continue;
        }
        if (numb >= 0){
            sum += numb;
            std::cout << "Сумма: " << sum << std::endl;
        } else {
            std::cout << "некорректный формат ввода" << std::endl;
        }
    }
    
    std::cout << "Bravo, you inputted 5312!";
    
    return 0;
}
