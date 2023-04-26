#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Vector {
public:
    Vector() {}

    void operator+(int element) { // adds an element to the end of the vector
        data_.push_back(element);
    }

    void operator++() { // adds an element to the beginning of the vector
        int element;
        cout << "Enter an element to add to the beginning of the vector: ";
        cin >> element;
        data_.insert(data_.begin(), element);
    }

    void operator++(int) { // adds an element to the end of the vector
        int element;
        cout << "Enter an element to add to the end of the vector: ";
        cin >> element;
        data_.push_back(element);
    }

    int& operator[](int index) { // access by index
        if (index < 0 || index >= data_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    void print() {
        cout << "Vector: ";
        for (const auto& element : data_) {
            cout << element << " ";
        }
        cout << endl;
    }

private:
    vector<int> data_;
};

int main() {
    Vector v;
    try {
        v[0] = 10; // throws an exception
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int element;
        cout << "Enter element #" << i << ": ";
        cin >> element;
        v + element;
    }

    cout << "Enter an element to add to the beginning of the vector: ";
    ++v;

    cout << "Enter an element to add to the end of the vector: ";
    v++;
    v.print();

    cout << "Enter the index of the element to retrieve: ";
    int index;
    cin >> index;
    try {
        cout << "Element #" << index << " is " << v[index] << endl;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
