#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

const int MAX_SIZE = 10;  // Maximum matrix size

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to fill the matrix with random values between -5 and 9
void fillMatrixRandom(int A[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = getRandomNumber(-5, 9);
        }
    }
}

// Лінійний (прямий) пошук
int linearSearch(int arr[MAX_SIZE], int key, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Повертаємо індекс, якщо знайдено
        }
    }
    return -1; // Повертаємо -1, якщо не знайдено
}

// Лінійний (прямий) пошук з бар'єром
int linearSearchWithBarrier(int arr[MAX_SIZE], int key, int size) {
    int lastValue = arr[size - 1]; // Зберігаємо останній елемент масиву
    arr[size - 1] = key; // Встановлюємо бар'єр

    int i = 0;
    while (arr[i] != key) {
        ++i;
    }

    arr[size - 1] = lastValue; // Відновлюємо останній елемент

    if (i < size - 1 || arr[size - 1] == key) {
        return i; // Повертаємо індекс, якщо знайдено
    }

    return -1; // Повертаємо -1, якщо не знайдено
}

void swapDiagonalElementsLinearSearch(int A[MAX_SIZE][MAX_SIZE], int size) {
    int firstPositiveRow = -1;
    int lastNegativeRow = -1;

    // Знаходження першого додатнього елемента на побічній діагоналі
    for (int i = 0; i < size; ++i) {
        if (A[i][size - 1 - i] > 0) {
            firstPositiveRow = i;
            break;
        }
    }

    // Знаходження останнього від'ємного елемента на побічній діагоналі
    for (int i = size - 1; i >= 0; --i) {
        if (A[i][size - 1 - i] < 0) {
            lastNegativeRow = i;
            break;
        }
    }

    // Перевірка, чи знайдено обидва елементи
    if (firstPositiveRow != -1 && lastNegativeRow != -1) {
        // Виводимо значення знайдених елементів
        std::cout << "Знайдений перший додатній елемент: " << A[firstPositiveRow][size - 1 - firstPositiveRow] << '\n';
        std::cout << "Знайдений останній від'ємний елемент: " << A[lastNegativeRow][size - 1 - lastNegativeRow] << '\n';

        // Міняємо місцями перший додатний та останній від'ємний елемент на побічній діагоналі
        int temp = A[firstPositiveRow][size - 1 - firstPositiveRow];
        A[firstPositiveRow][size - 1 - firstPositiveRow] = A[lastNegativeRow][size - 1 - lastNegativeRow];
        A[lastNegativeRow][size - 1 - lastNegativeRow] = temp;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    std::cout << "Введіть розмір матриці (не більше " << MAX_SIZE << "): ";
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Некоректний розмір матриці. Розмір повинен бути від 1 до " << MAX_SIZE << ".\n";
        return 1;
    }

    const int p = size;
    int A[MAX_SIZE][MAX_SIZE];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    fillMatrixRandom(A, p);

    std::cout << "Початкова матриця:\n";
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }

    swapDiagonalElementsLinearSearch(A, p);

    std::cout << "Змінена матриця:\n";
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

