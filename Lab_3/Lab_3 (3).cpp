#include <iostream>
#include <stack>
#include <Windows.h>
using namespace std;

bool is_correct_sequence(const string &sequence) {
  // Створюємо стек для дужок
  stack<char> s;

  // Проходимо послідовність дужок
  for (char c : sequence) {
    // Якщо дужка відкривається, додаємо її в стек
    if (c == '(' || c == '[') {
      s.push(c);
    } else if (c == ')' || c == ']') {
      // Якщо дужка закривається, перевіряємо, чи відповідає вона дужці в стеку
      if (s.empty() || (c == ')' && s.top() != '(') || (c == ']' && s.top() != '[')) {
        return false;
      }
      s.pop();
    }
  }

  // Якщо в стеку залишилися дужки, послідовність неправильна
  return s.empty();
}

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  // Вводимо послідовність дужок
  string sequence;
  cin >> sequence;

  // Перевіряємо правильність послідовності
  bool is_correct = is_correct_sequence(sequence);

  // Виводимо результат
  if (is_correct) {
    cout << "Послідовність правильна" << endl;
  } else {
    cout << "Послідовність неправильна" << endl;
  }

  return 0;
}

