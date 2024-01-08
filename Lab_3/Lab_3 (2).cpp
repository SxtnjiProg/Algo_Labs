#include <iostream>
#include <stack>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ��������� ��� ����� ��� ����� �����
    stack<int> evenStack;
    stack<int> oddStack;

    // �������� ������� �����, �� ���������� ���� ������
    cout << "������ ������� ����� ��� �������� � ����: ";
    int count;
    cin >> count;

    // ������� ����� �� ����������� �� �� �������
    cout << "������ " << count << " �����:\n";
    for (int i = 0; i < count; ++i) {
        int n;
        cin >> n;

        // ������� ����� �� ������� �� ���� �������
        if (n % 2 == 0) {
            evenStack.push(n);
        } else {
            oddStack.push(n);
        }
    }

    // �������� ���� ������ �����
    cout << "�������� ������� �����: ";
    while (!evenStack.empty()) {
        cout << evenStack.top() << " ";
        evenStack.pop();
    }

    cout << endl;

    // �������� ���� �������� �����
    cout << "�������� ��������� �����: ";
    while (!oddStack.empty()) {
        cout << oddStack.top() << " ";
        oddStack.pop();
    }

    cout << endl;

    return 0;
}

