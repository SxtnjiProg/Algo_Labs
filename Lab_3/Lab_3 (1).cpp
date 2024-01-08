#include <iostream>
#include <stack>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  // ��������� ���� ��� ����� �����
  stack<int> s;

  // �������� ������� �����, �� ���������� ���� ������
  cout << "������ ������� ����� ��� �������� � ����: ";
  int count;
  cin >> count;

  // ������� ����� � ����
  cout << "������ " << count << " �����:\n";
  for (int i = 0; i < count; ++i) {
    int n;
    cin >> n;
    s.push(n);
  }

  // �������� ���� �� �����
  cout << "�������� �����: ";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;

  return 0;
}

