#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <Windows.h>


int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Частина 5.4.1
    std::cout << "Частина 5.4.1: Введіть цілі числа (0 для завершення введення): ";
    std::list<int> numbers;
    int n;
    while (std::cin >> n && n != 0) {
        numbers.push_back(n);
    }
    std::cout << "Список цілих чисел: ";
    for (const auto& num : numbers) {
        std::cout << num << std::endl;
    }

    // Частина 5.4.2
    std::string input;
    std::cout << "Частина 5.4.2: Введіть рядок: ";
    std::cin.ignore(); // Очищення буфера перед getline
    std::getline(std::cin, input);
    std::list<char> characters(input.begin(), input.end());
    std::cout << "Список символів:" << std::endl;
    for (const auto& ch : characters) {
        std::cout << ch << std::endl;
    }
    std::cout << "Частина 5.4.3: Введіть рядок: ";
    std::string input;
    std::getline(std::cin, input);

    std::list<std::string> atoms;
    std::istringstream iss(input);
    std::string atom;

    while (iss >> atom) {
        atoms.push_back(atom);
    }

    std::cout << "Список атомів:" << std::endl;
    if (atoms.empty()) {
        std::cout << "[]" << std::endl;
    } else {
        std::cout << "[";
        for (auto it = atoms.begin(); it != atoms.end(); ++it) {
            if (it != atoms.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}

