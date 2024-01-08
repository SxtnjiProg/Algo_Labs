#include <iostream>
#include <list>
#include <string>
#include <Windows.h>

using namespace std;

class Family {
public:
    string husbandName;
    string wifeName;
    int numberOfChildren;
    int income;
    bool isWorking;
    int husbandAge;
    int wifeAge;

    Family(string hName, string wName, int children, int money, bool working, int hAge, int wAge)
        : husbandName(hName), wifeName(wName), numberOfChildren(children), income(money), isWorking(working), husbandAge(hAge), wifeAge(wAge) {}
};

void printFamily(const Family& f) {
    cout << "({Чоловік: " << f.husbandName << " (Вік: " << f.husbandAge << "), "
         << "Дружина: " << f.wifeName << " (Вік: " << f.wifeAge << "), "
         << "Діти: " << f.numberOfChildren
         << ", Дохід: " << f.income
         << ", Працює: " << (f.isWorking ? "Так" : "Ні") << "})\n";
}

class PriorityFamilyQueue {
private:
    list<Family> familyQueue;

public:
    void insertFamily(const Family& newFamily) {
        auto it = familyQueue.begin();
        while (it != familyQueue.end() && compareFamily(newFamily, *it)) {
            ++it;
        }
        familyQueue.insert(it, newFamily);
    }

    void removeFamily() {
        if (!familyQueue.empty()) {
            familyQueue.pop_front();
        } else {
            cout << "Черга порожня.\n";
        }
    }

    void printQueue() const {
        cout << "Поточний стан черги сімей:\n";
        for (const Family& f : familyQueue) {
            printFamily(f);
        }
        cout << "\n";
    }

void modifyFamily(int index) {
    if (index >= 0 && index < familyQueue.size()) {
        auto it = familyQueue.begin();
        advance(it, index);

        Family& modifiedFamily = *it;

        cout << "Виберіть параметр для зміни:\n"
             << "1. Ім'я чоловіка\n"
             << "2. Ім'я дружини\n"
             << "3. Кількість дітей\n"
             << "4. Дохід\n"
             << "5. Працює родина? (1 - так, 0 - ні)\n"
             << "6. Вік чоловіка\n"
             << "7. Вік дружини\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
                cout << "Введіть нове ім'я чоловіка: ";
                cin >> modifiedFamily.husbandName;
                break;
            case 2:
            	system("cls");
                cout << "Введіть нове ім'я дружини: ";
                cin >> modifiedFamily.wifeName;
                break;
            case 3:
            	system("cls");
                cout << "Введіть нову кількість дітей: ";
                cin >> modifiedFamily.numberOfChildren;
                break;
            case 4:
            	system("cls");
                cout << "Введіть новий дохід: ";
                cin >> modifiedFamily.income;
                break;
            case 5:
            	system("cls");
                cout << "Чи працює родина? (1 - так, 0 - ні): ";
                cin >> modifiedFamily.isWorking;
                break;
            case 6:
            	system("cls");
                cout << "Введіть новий вік чоловіка: ";
                cin >> modifiedFamily.husbandAge;
                break;
            case 7:
            	system("cls");
                cout << "Введіть новий вік дружини: ";
                cin >> modifiedFamily.wifeAge;
                break;
            default:
                cout << "Невірний вибір. Зміни не виконано.\n";
                break;
        }

        cout << "Інформацію про сім'ю успішно оновлено.\n";
    } else {
        cout << "Невірний індекс. Будь ласка, введіть дійсний індекс.\n";
    }
}

    void removeFirstFamily() {
        if (!familyQueue.empty()) {
            cout << "Видаляємо першу сім'ю з черги:\n";
            printFamily(familyQueue.front());
            familyQueue.pop_front();
        } else {
            cout << "Черга порожня. Немає сім'ї для видалення.\n";
        }
    }

    void removeLastFamily() {
        if (!familyQueue.empty()) {
            cout << "Видаляємо останню сім'ю з черги:\n";
            printFamily(familyQueue.back());
            familyQueue.pop_back();
        } else {
            cout << "Черга порожня. Немає сім'ї для видалення.\n";
        }
    }

private:
    bool compareFamily(const Family& f1, const Family& f2) const {
        if (f1.numberOfChildren != f2.numberOfChildren) {
            return f1.numberOfChildren < f2.numberOfChildren;
        } else if (f1.income != f2.income) {
            return f1.income > f2.income;
        } else if (f1.isWorking != f2.isWorking) {
            return f1.isWorking && !f2.isWorking;
        } else {
            if (f1.husbandAge + f1.wifeAge != f2.husbandAge + f2.wifeAge) {
                return f1.husbandAge + f1.wifeAge < f2.husbandAge + f2.wifeAge;
            } else {
                return f1.husbandAge < f2.husbandAge;
            }
        }
    }
};

int main() {
    PriorityFamilyQueue priorityFamilyQueue;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    Family family1("Максим", "Софія", 2, 50000, true, 35, 32);
    Family family2("Максим", "Ева", 1, 60000, true, 40, 38);
    Family family3("Максим", "Анастасія", 3, 75000, false, 45, 42);

    priorityFamilyQueue.insertFamily(family1);
    priorityFamilyQueue.insertFamily(family2);
    priorityFamilyQueue.insertFamily(family3);
    
    
    
    
    int choice;
    do {
        cout << "Оберіть опцію:\n"
                "1. Додати сім'ю до черги\n"
                "2. Видалити сім'ю з черги\n"
                "3. Вивести поточний стан черги\n"
                "4. Змінити інформацію про сім'ю\n"
                "5. Видалити першу сім'ю з черги\n"
                "6. Видалити останню сім'ю з черги\n"
                "0. Вихід\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                string hName, wName;
                int children, money, hAge, wAge;
                bool working;
                system("cls");

                cout << "Введіть ім'я чоловіка: ";
                cin >> hName;
                cout << "Введіть ім'я дружини: ";
                cin >> wName;
                cout << "Введіть кількість дітей: ";
                cin >> children;
                cout << "Введіть кількість доходів: ";
                cin >> money;
                cout << "Чи працює родина? (1 - так, 0 - ні): ";
                cin >> working;
                cout << "Введіть вік чоловіка: ";
                cin >> hAge;
                cout << "Введіть вік дружини: ";
                cin >> wAge;

                Family newFamily(hName, wName, children, money, working, hAge, wAge);
                priorityFamilyQueue.insertFamily(newFamily);
                break;
            }
            case 2:
            	system("cls");
                priorityFamilyQueue.removeFamily();
                break;
            case 3:
            	system("cls");
                priorityFamilyQueue.printQueue();
                break;
            case 4: {
                int index;
                system("cls");
                cout << "Введіть індекс сім'ї для зміни: ";
                cin >> index;
                priorityFamilyQueue.modifyFamily(index);
                break;
            }
            case 5:
            	system("cls");
                priorityFamilyQueue.removeFirstFamily();
                break;
            case 6:
            	system("cls");
                priorityFamilyQueue.removeLastFamily();
                break;
            case 0:
            	system("cls");
                cout << "Дякую за використання програми. До побачення!\n";
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

