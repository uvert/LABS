#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<double> createDeque(int count) {
    deque<double> myDeque;
    for (int i = 0; i < count; i++) {
        double value;
        cout << "Enter value #" << i + 1 << ": ";
        cin >> value;
        myDeque.push_back(value);
    }
    return myDeque;
}

void insertByKey(deque<double>& myDeque, double key, int pos) {
    auto it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.insert(myDeque.begin() + pos, *it);
    }
}

void eraseByKey(deque<double>& myDeque, double key) {
    auto it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
}

void subtractMinMax(deque<double>& myDeque) {
    auto minmax = minmax_element(myDeque.begin(), myDeque.end());
    double diff = *(minmax.second) - *(minmax.first);

    for (auto& elem : myDeque) {
        elem -= diff;
    }
}

int main() {
    int count;
    cout << "Enter the number of values to enter: ";
    cin >> count;

    deque<double> myDeque = createDeque(count);

    cout << "Deque contents: ";
    for (auto& elem : myDeque) {
        cout << elem << " ";
    }
    cout << endl;

    double key;
    cout << "Enter the key value to insert or remove: ";
    cin >> key;

    int pos;
    cout << "Enter the position to insert the key value: ";
    cin >> pos;

    insertByKey(myDeque, key, pos);
    eraseByKey(myDeque, key);
    subtractMinMax(myDeque);

    cout << "Deque contents after operations: ";
    for (auto& elem : myDeque) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
