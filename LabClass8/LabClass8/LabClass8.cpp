#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    string name;
    int age;

    virtual void print_info() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Abiturient : public Person {
public:
    int score;
    string specialty;
};

int main() {
    vector<Abiturient> group;

    char command;
    while (true) {
        cout << "Enter command (+ - m s z q): ";
        cin >> command;

        if (command == '+') {
            Abiturient abiturient;

            cout << "Enter name: ";
            cin >> abiturient.name;

            cout << "Enter age: ";
            cin >> abiturient.age;

            cout << "Enter score: ";
            cin >> abiturient.score;

            cout << "Enter specialty: ";
            cin >> abiturient.specialty;

            group.push_back(abiturient);
        }
        else if (command == '-') {
            int index;

            cout << "Enter index: ";
            cin >> index;

            if (index < 0 || index >= group.size()) {
                cout << "Invalid index!" << endl;
            }
            else {
                group.erase(group.begin() + index);
            }
        }
        else if (command == 'm') {
            int size;

            cout << "Enter size: ";
            cin >> size;

            group.resize(size);
        }
        else if (command == 's') {
            for (int i = 0; i < group.size(); i++) {
                group[i].print_info();
            }
        }
        else if (command == 'q') {
            break;
        }
        else if (command == 'z') {
            int sum = 0;
            for (int i = 0; i < group.size(); i++) {
                sum += group[i].age;
            }
            double average = (double)sum / group.size();
            cout << "Average age: " << average << endl;
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
