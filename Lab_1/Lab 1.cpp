#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 100;

// ��������, �� ����� ��� ������� � �����
bool isNumberInArray(int array[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

// ������� ��� ��������� ������ � �������� ������������ ���������
bool createArray(int array[], int &n) {
    // ����� �� �������� ������ ������� ��������
    cout << "������ ����� ������� ��������: ";
    int lowerBound;
    cin >> lowerBound;

    // ����� �� �������� ������� ������� ��������
    cout << "������ ������ ������� ��������: ";
    int upperBound;
    cin >> upperBound;

    // ����� �� �������� ������� �������� ������ (n)
    cout << "������ ������� �������� (n): ";
    cin >> n;

    srand(static_cast<unsigned int>(time(nullptr)));

    if (n <= N) {
        for (int i = 0; i < n; ) {
            int randomNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
            // ��������, �� ����� ��� ������� � �����
            if (!isNumberInArray(array, i, randomNumber)) {
                array[i] = randomNumber;
                i++;
            }
        }
        return true; // ����� ������ ���������
    } else {
        cout << "ʳ������ �������� �������� " << N << endl;
        return false; // �������: ������� �������� �������� N
    }
}


// ������� ��� ��������� ������ �� �����
void printArray(int array[], int n) {
    // ���� ��� ��������� ������� �������� ������
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ������� ��� ��������� ������ ������ � �������� ������ �������� ���� ������������� ��������
void createNewArray(int array[], int &n, int newArray[], int &newN) {
    if (n <= 0) {
        cout << "����� �������. ��������� �������� ����� �����." << endl;
        return;
    }

    int maxElement = array[0];
    int maxIndex = 0;

    // ����������� ������������� �������� � ���� �������
    for (int i = 1; i < n; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
            maxIndex = i;
        }
    }

    // ���������� ������ ������ ��������� ������� ���������� ���� �������������
    newN = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        if (array[i] > 0 && array[i] % 2 == 0) {
            newArray[newN] = array[i];
            newN++;
        }
    }
}

// ������� ��� ��������� �������� � ��������� ��������� �� ������������ �������� ����������
void removeOddIndexedElements(int array[], int &n) {
    if (n <= 0) {
        cout << "����� �������. ��������� �������� ��������." << endl;
        return;
    }

    int newIndex = 0;
    // ���� ��� ��������� �������� � ��������� ��������� �� ������������ ������ �������� ����������
    for (int i = 1; i < n; i += 2) {
        array[newIndex] = array[i];
        newIndex++;
    }
    n = newIndex;
}
 int findMaxElement(int array[], int n) {
    int maxElement = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
	}	

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int array[N];
    int n = 0;

    int choice;
    do {
        cout << "\n********** ���� **********\n";
        cout << "1. �������� �����\n";
        cout << "2. ������� ����� �� ������������\n";
        cout << "3. ������ ������������ ������� ������\n";
        cout << "4. �������� ����� ����� � ������� ������ �������� ���� ������������� ��������\n";
        cout << "5. �������� �������� � ��������� ���������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!createArray(array, n)) {
                    cout << "������� ��� �������� ������.\n";
                }
                break;

            case 2:
                cout << "����� �� ������������: ";
                printArray(array, n);
                break;

            case 3:
                if (n > 0) {
                    int maxElement = findMaxElement(array, n);
                    cout << "������������ ������� ������: " << maxElement << endl;
                } else {
                    cout << "����� �������. ��������� ������ ������������ �������." << endl;
                }
                break;

            case 4:
                if (n > 0) {
                    int newArray[N];
                    int newN = 0;
                    createNewArray(array, n, newArray, newN);
                    cout << "����� ����� � ������� ������ �������� ���� ������������� ��������: ";
                    printArray(newArray, newN);
                } else {
                    cout << "����� �������. ��������� �������� ����� �����." << endl;
                }
                break;

            case 5:
                removeOddIndexedElements(array, n);
                cout << "����� ���� ��������� �������� � ��������� ���������: ";
                printArray(array, n);
                break;

            case 0:
                cout << "�������� �����������.\n";
                break;

            default:
                cout << "������� ����. ��������� �� ���.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

