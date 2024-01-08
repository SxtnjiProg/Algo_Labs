#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 100;

// Перевірка, чи число вже присутнє в масиві
bool isNumberInArray(int array[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

// Функція для створення масиву з введених користувачем параметрів
bool createArray(int array[], int &n) {
    // Запит на введення нижньої границі діапазону
    cout << "Введіть нижню границю діапазону: ";
    int lowerBound;
    cin >> lowerBound;

    // Запит на введення верхньої границі діапазону
    cout << "Введіть верхню границю діапазону: ";
    int upperBound;
    cin >> upperBound;

    // Запит на введення кількості елементів масиву (n)
    cout << "Введіть кількість елементів (n): ";
    cin >> n;

    srand(static_cast<unsigned int>(time(nullptr)));

    if (n <= N) {
        for (int i = 0; i < n; ) {
            int randomNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
            // Перевірка, чи число вже присутнє в масиві
            if (!isNumberInArray(array, i, randomNumber)) {
                array[i] = randomNumber;
                i++;
            }
        }
        return true; // Масив успішно заповнено
    } else {
        cout << "Кількість елементів перевищує " << N << endl;
        return false; // Помилка: кількість елементів перевищує N
    }
}


// Функція для виведення масиву на екран
void printArray(int array[], int n) {
    // Цикл для виведення кожного елемента масиву
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Функція для створення нового масиву з додатних парних елементів після максимального елемента
void createNewArray(int array[], int &n, int newArray[], int &newN) {
    if (n <= 0) {
        cout << "Масив порожній. Неможливо створити новий масив." << endl;
        return;
    }

    int maxElement = array[0];
    int maxIndex = 0;

    // Знаходження максимального елемента і його індексу
    for (int i = 1; i < n; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
            maxIndex = i;
        }
    }

    // Заповнення нового масиву додатними парними елементами після максимального
    newN = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        if (array[i] > 0 && array[i] % 2 == 0) {
            newArray[newN] = array[i];
            newN++;
        }
    }
}

// Функція для видалення елементів з непарними індексами та розташування елементів неперервно
void removeOddIndexedElements(int array[], int &n) {
    if (n <= 0) {
        cout << "Масив порожній. Неможливо видалити елементи." << endl;
        return;
    }

    int newIndex = 0;
    // Цикл для видалення елементів з непарними індексами та розташування парних елементів неперервно
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
        cout << "\n********** Меню **********\n";
        cout << "1. Створити масив\n";
        cout << "2. Вивести масив до перетворення\n";
        cout << "3. Знайти максимальний елемент масиву\n";
        cout << "4. Створити новий масив з додатніх парних елементів після максимального елемента\n";
        cout << "5. Видалити елементи з непарними індексами\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!createArray(array, n)) {
                    cout << "Помилка при створенні масиву.\n";
                }
                break;

            case 2:
                cout << "Масив до перетворення: ";
                printArray(array, n);
                break;

            case 3:
                if (n > 0) {
                    int maxElement = findMaxElement(array, n);
                    cout << "Максимальний елемент масиву: " << maxElement << endl;
                } else {
                    cout << "Масив порожній. Неможливо знайти максимальний елемент." << endl;
                }
                break;

            case 4:
                if (n > 0) {
                    int newArray[N];
                    int newN = 0;
                    createNewArray(array, n, newArray, newN);
                    cout << "Новий масив з додатніх парних елементів після максимального елемента: ";
                    printArray(newArray, newN);
                } else {
                    cout << "Масив порожній. Неможливо створити новий масив." << endl;
                }
                break;

            case 5:
                removeOddIndexedElements(array, n);
                cout << "Масив після видалення елементів з непарними індексами: ";
                printArray(array, n);
                break;

            case 0:
                cout << "Програма завершується.\n";
                break;

            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

