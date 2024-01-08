#include <iostream>
#include <stack>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  // Створюємо стек для цілих чисел
  stack<int> s;

  // Введення кількості чисел, які користувач хоче ввести
  cout << "Введіть кількість чисел для введення у стек: ";
  int count;
  cin >> count;

  // Вводимо числа у стек
  cout << "Введіть " << count << " чисел:\n";
  for (int i = 0; i < count; ++i) {
    int n;
    cin >> n;
    s.push(n);
  }

  // Виводимо стек на екран
  cout << "Елементи стеку: ";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;

  return 0;
}

