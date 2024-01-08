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
    cout << "({������: " << f.husbandName << " (³�: " << f.husbandAge << "), "
         << "�������: " << f.wifeName << " (³�: " << f.wifeAge << "), "
         << "ĳ��: " << f.numberOfChildren
         << ", �����: " << f.income
         << ", ������: " << (f.isWorking ? "���" : "ͳ") << "})\n";
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
            cout << "����� �������.\n";
        }
    }

    void printQueue() const {
        cout << "�������� ���� ����� ����:\n";
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

        cout << "������� �������� ��� ����:\n"
             << "1. ��'� �������\n"
             << "2. ��'� �������\n"
             << "3. ʳ������ ����\n"
             << "4. �����\n"
             << "5. ������ ������? (1 - ���, 0 - �)\n"
             << "6. ³� �������\n"
             << "7. ³� �������\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
                cout << "������ ���� ��'� �������: ";
                cin >> modifiedFamily.husbandName;
                break;
            case 2:
            	system("cls");
                cout << "������ ���� ��'� �������: ";
                cin >> modifiedFamily.wifeName;
                break;
            case 3:
            	system("cls");
                cout << "������ ���� ������� ����: ";
                cin >> modifiedFamily.numberOfChildren;
                break;
            case 4:
            	system("cls");
                cout << "������ ����� �����: ";
                cin >> modifiedFamily.income;
                break;
            case 5:
            	system("cls");
                cout << "�� ������ ������? (1 - ���, 0 - �): ";
                cin >> modifiedFamily.isWorking;
                break;
            case 6:
            	system("cls");
                cout << "������ ����� �� �������: ";
                cin >> modifiedFamily.husbandAge;
                break;
            case 7:
            	system("cls");
                cout << "������ ����� �� �������: ";
                cin >> modifiedFamily.wifeAge;
                break;
            default:
                cout << "������� ����. ���� �� ��������.\n";
                break;
        }

        cout << "���������� ��� ��'� ������ ��������.\n";
    } else {
        cout << "������� ������. ���� �����, ������ ������ ������.\n";
    }
}

    void removeFirstFamily() {
        if (!familyQueue.empty()) {
            cout << "��������� ����� ��'� � �����:\n";
            printFamily(familyQueue.front());
            familyQueue.pop_front();
        } else {
            cout << "����� �������. ���� ��'� ��� ���������.\n";
        }
    }

    void removeLastFamily() {
        if (!familyQueue.empty()) {
            cout << "��������� ������� ��'� � �����:\n";
            printFamily(familyQueue.back());
            familyQueue.pop_back();
        } else {
            cout << "����� �������. ���� ��'� ��� ���������.\n";
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
   
    Family family1("������", "�����", 2, 50000, true, 35, 32);
    Family family2("������", "���", 1, 60000, true, 40, 38);
    Family family3("������", "��������", 3, 75000, false, 45, 42);

    priorityFamilyQueue.insertFamily(family1);
    priorityFamilyQueue.insertFamily(family2);
    priorityFamilyQueue.insertFamily(family3);
    
    
    
    
    int choice;
    do {
        cout << "������ �����:\n"
                "1. ������ ��'� �� �����\n"
                "2. �������� ��'� � �����\n"
                "3. ������� �������� ���� �����\n"
                "4. ������ ���������� ��� ��'�\n"
                "5. �������� ����� ��'� � �����\n"
                "6. �������� ������� ��'� � �����\n"
                "0. �����\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                string hName, wName;
                int children, money, hAge, wAge;
                bool working;
                system("cls");

                cout << "������ ��'� �������: ";
                cin >> hName;
                cout << "������ ��'� �������: ";
                cin >> wName;
                cout << "������ ������� ����: ";
                cin >> children;
                cout << "������ ������� ������: ";
                cin >> money;
                cout << "�� ������ ������? (1 - ���, 0 - �): ";
                cin >> working;
                cout << "������ �� �������: ";
                cin >> hAge;
                cout << "������ �� �������: ";
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
                cout << "������ ������ ��'� ��� ����: ";
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
                cout << "����� �� ������������ ��������. �� ���������!\n";
                break;
            default:
                cout << "������� ����. ��������� �� ���.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

