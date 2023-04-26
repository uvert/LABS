#include <iostream>
#include <cstring>

using namespace std;

class Vector {
private:
    int* arr;
    int size;
public:
    // Конструкторы
    Vector() {
        arr = nullptr;
        size = 0;
    }

    Vector(int s) {
        arr = new int[s];
        size = s;
    }

    Vector(const Vector& v) {
        size = v.size;
        arr = new int[size];
        memcpy(arr, v.arr, sizeof(int) * size);
    }

    // Деструктор
    ~Vector() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }

    // Оператор присваивания
    Vector& operator=(const Vector& v) {
        if (this != &v) {
            if (arr != nullptr) {
                delete[] arr;
            }
            size = v.size;
            arr = new int[size];
            memcpy(arr, v.arr, sizeof(int) * size);
        }
        return *this;
    }

    // Оператор доступа по индексу
    int operator[](int index) const {
        return arr[index];
    }

    // Оператор сложения двух векторов
    Vector operator+(const Vector& v) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + v.arr[i];
        }
        return result;
    }

    // Оператор добавления числа к вектору
    Vector operator+(int number) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + number;
        }
        return result;
    }

    // Оператор перехода к предыдущему элементу
    class Iterator {
    private:
        int* ptr;
    public:
        Iterator(int* p) {
            ptr = p;
        }

        Iterator operator--() {
            --ptr;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        int& operator*() {
            return *ptr;
        }
    };

    Iterator begin() {
        return Iterator(arr);
    }

    Iterator end() {
        return Iterator(arr - 1);
    }

    // Оператор ввода
    friend istream& operator>>(istream& in, Vector& v) {
        in >> v.size;
        v.arr = new int[v.size];
        for (int i = 0; i < v.size; i++) {
            in >> v.arr[i];
        }
        return in;
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& out, const Vector& v) {
        for (int i = 0; i < v.size; i++) {
            out << v.arr[i] << " ";
        }
        return out;
    }
};

int main() {
    Vector v1, v2, v3, v4;
    int num;

    cout << "Enter the size of the first vector: "; // вводить n+1 чисел. первое число - "размер", остальные - "наполнение" 
    cin >> v1;
    cout << "Enter the size of the second vector: "; // вводить n+1 чисел. первое число - "размер", остальные - "наполнение" 
    cin >> v2;

    cout << "First vector: " << v1 << endl;
    cout << "Second vector: " << v2 << endl;
    cout << "Enter a number to add to the vectors: ";
    cin >> num;

    v3 = v1 + num;
    cout << "Result of adding " << num << " to the first vector: " << v3 << endl;

    v4 = v2 + num;
    cout << "Result of adding " << num << " to the second vector: " << v4 << endl;

    v3 = v1 + v2;
    cout << "Result of adding the first and second vectors: " << v3 << endl;


    return 0;
}
