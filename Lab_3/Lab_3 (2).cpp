#include <iostream>
#include <stack>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створюємо два стеки для цілих чисел
    stack<int> evenStack;
    stack<int> oddStack;

    // Введення кількості чисел, які користувач хоче ввести
    cout << "Введіть кількість чисел для введення у стек: ";
    int count;
    cin >> count;

    // Вводимо числа та розподіляємо їх між стеками
    cout << "Введіть " << count << " чисел:\n";
    for (int i = 0; i < count; ++i) {
        int n;
        cin >> n;

        // Розподіл числа між стеками за його парністю
        if (n % 2 == 0) {
            evenStack.push(n);
        } else {
            oddStack.push(n);
        }
    }

    // Виводимо стек парних чисел
    cout << "Елементи парного стеку: ";
    while (!evenStack.empty()) {
        cout << evenStack.top() << " ";
        evenStack.pop();
    }

    cout << endl;

    // Виводимо стек непарних чисел
    cout << "Елементи непарного стеку: ";
    while (!oddStack.empty()) {
        cout << oddStack.top() << " ";
        oddStack.pop();
    }

    cout << endl;

    return 0;
}

