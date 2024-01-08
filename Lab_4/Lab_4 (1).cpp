#include <iostream>
#include <deque>
#include <Windows.h>
#include <stdexcept>
using namespace std;

// Функція для виведення поточного стану дека
void printDeque(const deque<int>& myDeque) {
    cout << "Дек: ";
    for (int element : myDeque) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    deque<int> myDeque;

    char userInput;
    do {
        cout << "Оберіть опцію:\n"
                "1. Додати елемент до деку\n"
                "2. Показати дек\n"
                "3. Перевірити чи дек є паліндромом\n"
                "0. Вихід\n";
        cin >> userInput;

        switch (userInput) {
            case '1': {
                cout << "Введіть елемент для додавання до деку: ";
                int element;
                cin >> element;
                myDeque.push_back(element);
                break;
            }
            case '2':
                printDeque(myDeque);
                break;
            case '3': {
                bool isPalindrome = true;
                for (int i = 0; i < myDeque.size() / 2; i++) {
                    if (myDeque[i] != myDeque[myDeque.size() - 1 - i]) {
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome) {
                    cout << "Дек є паліндромом." << endl;
                } else {
                    cout << "Дек не є паліндромом." << endl;
                }
                break;
            }
            case '0':
                cout << "Дякую за використання програми. До побачення!\n";
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }

    } while (userInput != '0');

    return 0;
}

