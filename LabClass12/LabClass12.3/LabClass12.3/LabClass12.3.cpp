#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

template<typename T>
class Vector {
private:
    map<int, T> data;

public:
    Vector() {}

    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) {
        return data[index];
    }

    void add(Vector<T> other) {
        for (auto it : other.data) {
            data[it.first] += it.second;
        }
    }

    void add(T constant) {
        for (auto it : data) {
            data[it.first] += constant;
        }
    }

    void insert(int index, T value) {
        data.insert(make_pair(index, value));
    }

    void remove(int index) {
        data.erase(index);
    }

    void subtractMinMax() {
        T min_val = (*min_element(data.begin(), data.end(), [](auto a, auto b) {return a.second < b.second; })).second;
        T max_val = (*max_element(data.begin(), data.end(), [](auto a, auto b) {return a.second < b.second; })).second;
        T diff = max_val - min_val;
        for (auto& it : data) {
            it.second -= diff;
        }
    }
};

int main() {
    Vector<int> v;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter the value for element " << i << ": ";
        cin >> value;
        v.set(i, value);
    }

    Vector<int> w;
    cout << "Enter the values for the second vector:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter the value for element " << i << ": ";
        cin >> value;
        w.set(i, value);
    }

    v.add(w);

    int constant;
    cout << "Enter a constant value to add to all elements: ";
    cin >> constant;
    v.add(constant);

    int insert_index, insert_value;
    cout << "Enter the index and value to insert: ";
    cin >> insert_index >> insert_value;
    v.insert(insert_index, insert_value);

    int remove_index;
    cout << "Enter the index to remove: ";
    cin >> remove_index;
    v.remove(remove_index);

    v.subtractMinMax();

    cout << "The final vector is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v.get(i) << endl;
    }

    return 0;
}
