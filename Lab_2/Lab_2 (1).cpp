#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <Windows.h>


int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ������� 5.4.1
    std::cout << "������� 5.4.1: ������ ��� ����� (0 ��� ���������� ��������): ";
    std::list<int> numbers;
    int n;
    while (std::cin >> n && n != 0) {
        numbers.push_back(n);
    }
    std::cout << "������ ����� �����: ";
    for (const auto& num : numbers) {
        std::cout << num << std::endl;
    }

    // ������� 5.4.2
    std::string input;
    std::cout << "������� 5.4.2: ������ �����: ";
    std::cin.ignore(); // �������� ������ ����� getline
    std::getline(std::cin, input);
    std::list<char> characters(input.begin(), input.end());
    std::cout << "������ �������:" << std::endl;
    for (const auto& ch : characters) {
        std::cout << ch << std::endl;
    }
    std::cout << "������� 5.4.3: ������ �����: ";
    std::string input;
    std::getline(std::cin, input);

    std::list<std::string> atoms;
    std::istringstream iss(input);
    std::string atom;

    while (iss >> atom) {
        atoms.push_back(atom);
    }

    std::cout << "������ �����:" << std::endl;
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

