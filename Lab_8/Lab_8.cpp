#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left_half(n1);
    vector<int> right_half(n2);

    for (int i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        }
        else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, M;

    cout << "Enter N (1 < N < 256): ";
    cin >> N;

    while (N <= 1 || N >= 256) {
        cout << "Invalid value for N. Enter N again (1 < N < 256): ";
        cin >> N;
    }

    cout << "Enter M (1 < M < 256): ";
    cin >> M;

    while (M <= 1 || M >= 256) {
        cout << "Invalid value for M. Enter M again (1 < M < 256): ";
        cin >> M;
    }

    vector<int> sequence_N(N);

    cout << "Enter sequence of N keys:\n";
    for (int i = 0; i < N; i++) {
        cout << "Key " << i + 1 << ": ";
        cin >> sequence_N[i];
    }

    vector<int> sequence_M(M);

    cout << "Enter sequence of M keys:\n";
    for (int i = 0; i < M; i++) {
        cout << "Key " << i + 1 << ": ";
        cin >> sequence_M[i];
    }

    vector<int> mergedSequence(N + M);  // Combine both arrays into one

    // Merge the sequences
    merge(sequence_N.begin(), sequence_N.end(), sequence_M.begin(), sequence_M.end(), mergedSequence.begin());

    mergeSort(mergedSequence, 0, N + M - 1);

    cout << "Merged and sorted sequence: ";
    for (int i = 0; i < N + M; i++) {
        cout << mergedSequence[i] << " ";
    }
    cout << endl;

    for (int key_M : sequence_M) {
        int index = binarySearch(mergedSequence, key_M);
        if (index != -1) {
            cout << "Element " << key_M << " is at position " << index + 1 << "." << endl;
        }
        else {
            cout << "Element " << key_M << " not found in the merged sequence." << endl;
        }
    }

    return 0;
}
int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int N, M;

    cout << "Введіть N (1 < N < 256): ";
    cin >> N;

    while (N <= 1 || N >= 256) {
        cout << "Некоректне значення N. Введіть N знову (1 < N < 256): ";
        cin >> N;
    }

    cout << "Введіть M (1 < M < 256): ";
    cin >> M;

    while (M <= 1 || M >= 256) {
        cout << "Некоректне значення M. Введіть M знову (1 < M < 256): ";
        cin >> M;
    }

    vector<int> sequence_N(N);

    cout << "Введіть послідовність N ключів:\n";
    for (int i = 0; i < N; i++) {
        cout << "Ключ " << i + 1 << ": ";
        cin >> sequence_N[i];
    }

    vector<int> sequence_M(M);

    cout << "Введіть послідовність M ключів:\n";
    for (int i = 0; i < M; i++) {
        cout << "Ключ " << i + 1 << ": ";
        cin >> sequence_M[i];
    }

    mergeSort(sequence_N, 0, N - 1);

    cout << "Відсортована послідовність N: ";
    for (int i = 0; i < N; i++) {
        cout << sequence_N[i] << " ";
    }
    cout << endl;

    for (int key_M : sequence_M) {
        int index = binarySearch(sequence_N, key_M);
        if (index != -1) {
            cout << "Елемент " << key_M << " є у послідовності N на позиції " << index + 1 << "." << endl;
        }
        else {
            cout << "Елемент " << key_M << " не знайдено у послідовності N." << endl;
        }
    }

    return 0;
}

