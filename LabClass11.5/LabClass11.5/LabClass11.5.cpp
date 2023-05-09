#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class VectorAdapter {
private:
    vector<T> v;
public:
    VectorAdapter() {}

    void push_back(T elem) {
        v.push_back(elem);
    }

    T operator[](int index) {
        return v[index];
    }

    int size() {
        return v.size();
    }

    void add(T val) {
        for (int i = 0; i < v.size(); i++) {
            v[i] += val;
        }
    }

    void subtract() {
        T maxElem = v[0], minElem = v[0];
        for (int i = 1; i < v.size(); i++) {
            maxElem = max(maxElem, v[i]);
            minElem = min(minElem, v[i]);
        }
        T diff = maxElem - minElem;
        for (int i = 0; i < v.size(); i++) {
            v[i] -= diff;
        }
    }

    void addAt(T elem, int pos) {
        v.insert(v.begin() + pos, elem);
    }

    void remove(T elem) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == elem) {
                v.erase(v.begin() + i);
                break;
            }
        }
    }

    VectorAdapter<T> operator+(VectorAdapter<T> other) {
        VectorAdapter<T> result;
        for (int i = 0; i < v.size(); i++) {
            result.push_back(v[i] + other[i]);
        }
        return result;
    }
};

int main() {
    VectorAdapter<int> v;

    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    cout << "Enter the elements of the vector:" << endl;
    for (int i = 0; i < size; i++) {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }

    int val;
    cout << "Enter a value to add to all elements of the vector: ";
    cin >> val;

    v.add(val);

    cout << "Vector elements after addition: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.subtract();

    cout << "Vector elements after subtraction: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    int index, elem;
    cout << "Enter an element to add: ";
    cin >> elem;
    cout << "Enter an index to add the element at: ";
    cin >> index;

    v.addAt(elem, index);

    cout << "Vector elements after adding at index " << index << ": ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Enter an element to remove: ";
    cin >> elem;

    v.remove(elem);

    cout << "Vector elements after removing " << elem << ": ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    VectorAdapter<int> v2;

    cout << "Enter the size of the second vector: ";
    cin >> size;
    cout << "Enter the elements of the second vector:" << endl;
    for (int i = 0; i < size; i++) {
        int elem;
        cin >> elem;
        v2.push_back(elem);
    }

    VectorAdapter<int> v3 = v + v2;

    cout << "Elements of the first vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Elements of the second vector: ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << "Elements of the third vector after adding the first two vectors: ";
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    return 0;
}
