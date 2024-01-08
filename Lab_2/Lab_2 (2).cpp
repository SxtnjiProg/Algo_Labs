#include <iostream>
#include <string>
#include <list>
#include <Windows.h>

using namespace std;
struct Date {
    int day;
    int month;
    int year;
};

struct Worker {
    string job;
    int salary;
};

struct FamilyMember {
    string firstName;
    string lastName;
    Date birthDate;
    Worker workInfo;
};

struct Family {
    FamilyMember husband;
    FamilyMember wife;
    list<FamilyMember> children;
};

list<Family> database = {
    {
        {"Джон", "Ганзуля", {9, 12, 1980}, {"Так", 10000}},
        {"Аня", "Ганзуля", {11, 11, 1982}, {"Так", 10000}},
        {
            {"Діма", "Ганзуля", {11, 12, 2005}, {"Ні", 0}},
            {"Андрій", "Ганузля", {13, 10, 2008}, {"Ні", 0}}
        }
    },
    {
        {"Боббі", "Кузів", {2, 2, 1975}, {"Так", 45000}},
        {"Гей", "Кузів", {2, 2, 1978}, {"Так", 500}},
        {
            {"Максим", "Кузів", {19, 2, 2002}, {"Ні", 0}},
            {"Ваня", "Кузів", {20, 12, 2007}, {"Ні", 0}},
            {"Юра", "Кузів", {10, 1, 2010}, {"Ні", 0}}
        }
    }
};

void addFamily() {
    Family family;

    cout << "Ім'я Чоловіка: ";
    cin >> family.husband.firstName;
    cout << "Фамілія Чоловіка: ";
    cin >> family.husband.lastName;
    cout << "Дата народження чоловіка (день місяць рік): ";
    cin >> family.husband.birthDate.day >> family.husband.birthDate.month >> family.husband.birthDate.year;
    cout << "Чи працює чоловік ?: ";
   	cin >> family.husband.workInfo.job;
    if (family.husband.workInfo.job == "Так") {
        std::cout << "Зарплатня: ";
        std::cin >> family.husband.workInfo.salary;
    } else {
        family.husband.workInfo.salary = 0;
    }

    cout << "Ім'я Жінки: ";
    cin >> family.wife.firstName;
    cout << "Фамілія Жінки: ";
    cin >> family.wife.lastName;
    cout << "Дата народження жінки (день місяць рік): ";
    cin >> family.wife.birthDate.day >> family.wife.birthDate.month >> family.wife.birthDate.year;
    cout << "Чи працює жінка: ";
    cin >> family.wife.workInfo.job;
    if (family.wife.workInfo.job == "Так") {
        cout << "Зарплатня: ";
        cin >> family.wife.workInfo.salary;
    } else {
        family.wife.workInfo.salary = 0;
    }

    int numChildren;
    cout << "Кількість дітей: ";
    cin >> numChildren;
    for (int i = 0; i < numChildren; ++i) {
        FamilyMember child;
        cout << "Ім'я дитини: ";
        cin >> child.firstName;
        cout << "Фамілія дитини: ";
        cin >> child.lastName;
        cout << "Дата народження дитини (день місяць рік): ";
        cin >> child.birthDate.day >> child.birthDate.month >> child.birthDate.year;
        cout << "Чи працює дитина: ";
        cin >> child.workInfo.job;
        if (child.workInfo.job == "Так") {
            cout << "Зарплатня: ";
            cin >> child.workInfo.salary;
        } else {
            child.workInfo.salary = 0;
        }

        family.children.push_back(child);
    }

    database.push_back(family);
}

void findFamiliesWithThreeChildren() {
    cout << "Сім'ї з трьома і більше дітьми:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.children.size() >= 3) {
            cout << "Сім'я " << familyNumber << ":\n"
                      << "Чоловік: " << family.husband.firstName << " " << family.husband.lastName << ".\n"
                      << "Жінка: " << family.wife.firstName << " " << family.wife.lastName << ".\n";
            int childNumber = 1;
            for (const FamilyMember& child : family.children) {
                cout << "Дитина " << childNumber << ": " << child.firstName << " " << child.lastName << ".\n";
                childNumber++;
            }
            cout << std::endl;
        }
        familyNumber++;
    }
}

void findWorkingWivesand3cids() {
    cout << "Дружини, які мають щонайменше трьох дітей та працюють:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.wife.workInfo.job != "Ні" && family.children.size() >= 3) {
            cout << "Сім'я " << familyNumber << ":\n"
                      << "Жінка: " << family.wife.firstName << " " << family.wife.lastName << ".\n"
                      << "Кількість дітей: " << family.children.size() << ".\n\n";
        }
        familyNumber++;
    }
}

void printAllNames() {
    cout << "Вивести всі сім'ї:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        cout << "Сім'я " << familyNumber << ":\n"
                  << "Чоловік: " << family.husband.firstName << " " << family.husband.lastName << ".\n"
                  << "Жінка: " << family.wife.firstName << " " << family.wife.lastName << ".\n";
        int childNumber = 1;
        for (const FamilyMember& child : family.children) {
            cout << "Дитина " << childNumber << ": " << child.firstName << " " << child.lastName << ".\n";
            childNumber++;
        }
        cout << std::endl;
        familyNumber++;
    }
}

void findWorkingWives() {
    cout << "Дружини, які працюють:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.wife.workInfo.job != "Ні") {
            cout << "Сім'я " << familyNumber << ":\n"
                      << "Жінка: " << family.wife.firstName << " " << family.wife.lastName << ".\n\n";
        }
        familyNumber++;
    }
}

void findPeopleWithIncomeLessThan1000() {
    cout << "Люди з доходом менше ніж 1000:" << std::endl;
    for (const Family& family : database) {
        if (family.husband.workInfo.salary < 1000) {
            cout << "Чоловік: " << family.husband.firstName << " " << family.husband.lastName << std::endl;
        }
        if (family.wife.workInfo.salary < 1000) {
            cout << "Жінка: " << family.wife.firstName << " " << family.wife.lastName << std::endl;
        }
        for (const FamilyMember& child : family.children) {
            if (child.workInfo.salary < 1000 && child.workInfo.job != "Ні") {
                cout << "Дитина: " << child.firstName << " " << child.lastName << std::endl;
            }
        }
    }
}

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice;
    do {
        cout << "1. Додати" << std::endl;
        cout << "2. Знайти сім'ю з 3 або більше дітьми" << std::endl;
        cout << "3. Знайти працюючих дружин з принаймні трьома дітьми" << std::endl;
        cout << "4. Знайти всіх працюючих дружин" << std::endl;
        cout << "5. Знайти прізвища людей з прибутком менше 1000" << std::endl;
        cout << "6. Вивести всіх" << std::endl;
        cout << "7. Вихід" << std::endl;
        cout << "Вибір ";
        cin >> choice;

        switch (choice) {
            case '1':
                addFamily();
                break;
            case '2':
                findFamiliesWithThreeChildren();
                break;
            case '3':
                findWorkingWivesand3cids();
                break;
            case '4':
                findWorkingWives();
                break;
            case '5':
                findPeopleWithIncomeLessThan1000();
                break;
            case '6':
                printAllNames();
                break;
            case '7':
                cout << "До побачення!" << std::endl;
                break;
            default:
                cout << "" << std::endl;
        }
    } while (choice != '7');

    return 0;
}

