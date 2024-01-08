#include <iostream>
#include <stack>
#include <Windows.h>
using namespace std;

bool is_correct_sequence(const string &sequence) {
  // ��������� ���� ��� �����
  stack<char> s;

  // ��������� ����������� �����
  for (char c : sequence) {
    // ���� ����� �����������, ������ �� � ����
    if (c == '(' || c == '[') {
      s.push(c);
    } else if (c == ')' || c == ']') {
      // ���� ����� �����������, ����������, �� ������� ���� ����� � �����
      if (s.empty() || (c == ')' && s.top() != '(') || (c == ']' && s.top() != '[')) {
        return false;
      }
      s.pop();
    }
  }

  // ���� � ����� ���������� �����, ����������� �����������
  return s.empty();
}

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  // ������� ����������� �����
  string sequence;
  cin >> sequence;

  // ���������� ����������� �����������
  bool is_correct = is_correct_sequence(sequence);

  // �������� ���������
  if (is_correct) {
    cout << "����������� ���������" << endl;
  } else {
    cout << "����������� �����������" << endl;
  }

  return 0;
}

