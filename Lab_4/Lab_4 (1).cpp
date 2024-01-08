#include <iostream>
#include <deque>
#include <Windows.h>
#include <stdexcept>
using namespace std;

// ������� ��� ��������� ��������� ����� ����
void printDeque(const deque<int>& myDeque) {
    cout << "���: ";
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
        cout << "������ �����:\n"
                "1. ������ ������� �� ����\n"
                "2. �������� ���\n"
                "3. ��������� �� ��� � ����������\n"
                "0. �����\n";
        cin >> userInput;

        switch (userInput) {
            case '1': {
                cout << "������ ������� ��� ��������� �� ����: ";
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
                    cout << "��� � ����������." << endl;
                } else {
                    cout << "��� �� � ����������." << endl;
                }
                break;
            }
            case '0':
                cout << "����� �� ������������ ��������. �� ���������!\n";
                break;
            default:
                cout << "������� ����. ��������� �� ���.\n";
                break;
        }

    } while (userInput != '0');

    return 0;
}

