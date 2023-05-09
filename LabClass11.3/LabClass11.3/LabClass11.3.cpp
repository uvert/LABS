#include <iostream>
#include <vector>

using namespace std;

class Vector {
private:
    vector<int> container; // Последовательный контейнер
public:
    // Конструктор класса
    Vector(vector<int> v) : container(v) {}

    // Операция доступа по индексу
    int operator[](int index) {
        return container[index];
    }

    // Операция сложения векторов
    Vector operator+(Vector v) {
        vector<int> result;
        for (int i = 0; i < container.size(); i++) {
            result.push_back(container[i] + v[i]);
        }
        return Vector(result);
    }

    // Операция добавления константы ко всем элементам вектора
    Vector operator+(int x) {
        vector<int> result;
        for (int i = 0; i < container.size(); i++) {
            result.push_back(container[i] + x);
        }
        return Vector(result);
    }

    // Поиск элемента по заданному ключу и добавление на заданную позицию
    void insert(int key, int position) {
        for (int i = 0; i < container.size(); i++) {
            if (container[i] == key) {
                container.insert(container.begin() + position, key);
                break;
            }
        }
    }

    // Поиск элемента по заданному ключу и удаление из контейнера
    void remove(int key) {
        for (int i = 0; i < container.size(); i++) {
            if (container[i] == key) {
                container.erase(container.begin() + i);
                break;
            }
        }
    }

    // Нахождение разницы между максимальным и минимальным элементами контейнера и вычитание из каждого элемента контейнера
    void subtractMaxMin() {
        int maxElement = container[0], minElement = container[0];
        for (int i = 1; i < container.size(); i++) {
            if (container[i] > maxElement) {
                maxElement = container[i];
            }
            if (container[i] < minElement) {
                minElement = container[i];
            }
        }
        int diff = maxElement - minElement;
        for (int i = 0; i < container.size(); i++) {
            container[i] -= diff;
        }
    }

    // Метод вывода содержимого контейнера
    void print() {
        for (int i = 0; i < container.size(); i++) {
            cout << container[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Заполнение вектора элементами, введенными пользователем
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    vector<int> elements(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    Vector v(elements);

    // Демонстрация работы всех методов класса
    cout << "Initial vector: ";
    v.print();

    int index;
    cout << "Enter the index: ";
    cin >> index;
    cout << "Element at index " << index << ": " << v[index] << endl;
    int constant;
    cout << "Enter a constant to add to the vector: ";
    cin >> constant;
    Vector v1 = v + constant;
    cout << "Vector after adding " << constant << " to each element: ";
    v1.print();

    Vector v2(elements);
    Vector v3 = v + v2;
    cout << "Vector after adding two vectors: ";
    v3.print();

    int key, position;
    cout << "Enter a key and position to insert: ";
    cin >> key >> position;
    v.insert(key, position);
    cout << "Vector after inserting " << key << " at position " << position << ": ";
    v.print();

    cout << "Enter a key to remove: ";
    cin >> key;
    v.remove(key);
    cout << "Vector after removing " << key << ": ";
    v.print();

    v.subtractMaxMin();
    cout << "Vector after subtracting the difference between max and min elements: ";
    v.print();

    return 0;
}
