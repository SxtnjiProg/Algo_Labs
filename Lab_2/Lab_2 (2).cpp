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
        {"����", "�������", {9, 12, 1980}, {"���", 10000}},
        {"���", "�������", {11, 11, 1982}, {"���", 10000}},
        {
            {"ĳ��", "�������", {11, 12, 2005}, {"ͳ", 0}},
            {"�����", "�������", {13, 10, 2008}, {"ͳ", 0}}
        }
    },
    {
        {"����", "����", {2, 2, 1975}, {"���", 45000}},
        {"���", "����", {2, 2, 1978}, {"���", 500}},
        {
            {"������", "����", {19, 2, 2002}, {"ͳ", 0}},
            {"����", "����", {20, 12, 2007}, {"ͳ", 0}},
            {"���", "����", {10, 1, 2010}, {"ͳ", 0}}
        }
    }
};

void addFamily() {
    Family family;

    cout << "��'� �������: ";
    cin >> family.husband.firstName;
    cout << "����� �������: ";
    cin >> family.husband.lastName;
    cout << "���� ���������� ������� (���� ����� ��): ";
    cin >> family.husband.birthDate.day >> family.husband.birthDate.month >> family.husband.birthDate.year;
    cout << "�� ������ ������ ?: ";
   	cin >> family.husband.workInfo.job;
    if (family.husband.workInfo.job == "���") {
        std::cout << "���������: ";
        std::cin >> family.husband.workInfo.salary;
    } else {
        family.husband.workInfo.salary = 0;
    }

    cout << "��'� Ƴ���: ";
    cin >> family.wife.firstName;
    cout << "����� Ƴ���: ";
    cin >> family.wife.lastName;
    cout << "���� ���������� ���� (���� ����� ��): ";
    cin >> family.wife.birthDate.day >> family.wife.birthDate.month >> family.wife.birthDate.year;
    cout << "�� ������ ����: ";
    cin >> family.wife.workInfo.job;
    if (family.wife.workInfo.job == "���") {
        cout << "���������: ";
        cin >> family.wife.workInfo.salary;
    } else {
        family.wife.workInfo.salary = 0;
    }

    int numChildren;
    cout << "ʳ������ ����: ";
    cin >> numChildren;
    for (int i = 0; i < numChildren; ++i) {
        FamilyMember child;
        cout << "��'� ������: ";
        cin >> child.firstName;
        cout << "����� ������: ";
        cin >> child.lastName;
        cout << "���� ���������� ������ (���� ����� ��): ";
        cin >> child.birthDate.day >> child.birthDate.month >> child.birthDate.year;
        cout << "�� ������ ������: ";
        cin >> child.workInfo.job;
        if (child.workInfo.job == "���") {
            cout << "���������: ";
            cin >> child.workInfo.salary;
        } else {
            child.workInfo.salary = 0;
        }

        family.children.push_back(child);
    }

    database.push_back(family);
}

void findFamiliesWithThreeChildren() {
    cout << "ѳ�'� � ������ � ����� �����:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.children.size() >= 3) {
            cout << "ѳ�'� " << familyNumber << ":\n"
                      << "������: " << family.husband.firstName << " " << family.husband.lastName << ".\n"
                      << "Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << ".\n";
            int childNumber = 1;
            for (const FamilyMember& child : family.children) {
                cout << "������ " << childNumber << ": " << child.firstName << " " << child.lastName << ".\n";
                childNumber++;
            }
            cout << std::endl;
        }
        familyNumber++;
    }
}

void findWorkingWivesand3cids() {
    cout << "�������, �� ����� ���������� ����� ���� �� ��������:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.wife.workInfo.job != "ͳ" && family.children.size() >= 3) {
            cout << "ѳ�'� " << familyNumber << ":\n"
                      << "Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << ".\n"
                      << "ʳ������ ����: " << family.children.size() << ".\n\n";
        }
        familyNumber++;
    }
}

void printAllNames() {
    cout << "������� �� ��'�:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        cout << "ѳ�'� " << familyNumber << ":\n"
                  << "������: " << family.husband.firstName << " " << family.husband.lastName << ".\n"
                  << "Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << ".\n";
        int childNumber = 1;
        for (const FamilyMember& child : family.children) {
            cout << "������ " << childNumber << ": " << child.firstName << " " << child.lastName << ".\n";
            childNumber++;
        }
        cout << std::endl;
        familyNumber++;
    }
}

void findWorkingWives() {
    cout << "�������, �� ��������:" << std::endl;
    int familyNumber = 1;
    for (const Family& family : database) {
        if (family.wife.workInfo.job != "ͳ") {
            cout << "ѳ�'� " << familyNumber << ":\n"
                      << "Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << ".\n\n";
        }
        familyNumber++;
    }
}

void findPeopleWithIncomeLessThan1000() {
    cout << "���� � ������� ����� �� 1000:" << std::endl;
    for (const Family& family : database) {
        if (family.husband.workInfo.salary < 1000) {
            cout << "������: " << family.husband.firstName << " " << family.husband.lastName << std::endl;
        }
        if (family.wife.workInfo.salary < 1000) {
            cout << "Ƴ���: " << family.wife.firstName << " " << family.wife.lastName << std::endl;
        }
        for (const FamilyMember& child : family.children) {
            if (child.workInfo.salary < 1000 && child.workInfo.job != "ͳ") {
                cout << "������: " << child.firstName << " " << child.lastName << std::endl;
            }
        }
    }
}

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice;
    do {
        cout << "1. ������" << std::endl;
        cout << "2. ������ ��'� � 3 ��� ����� �����" << std::endl;
        cout << "3. ������ ��������� ������ � �������� ������ �����" << std::endl;
        cout << "4. ������ ��� ��������� ������" << std::endl;
        cout << "5. ������ ������� ����� � ��������� ����� 1000" << std::endl;
        cout << "6. ������� ���" << std::endl;
        cout << "7. �����" << std::endl;
        cout << "���� ";
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
                cout << "�� ���������!" << std::endl;
                break;
            default:
                cout << "" << std::endl;
        }
    } while (choice != '7');

    return 0;
}

