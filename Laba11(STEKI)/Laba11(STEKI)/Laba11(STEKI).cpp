#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    int n;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        cout << "Enter the key for element " << i + 1 << ": ";
        cin >> key;
        st.push(key);
    }

    cout << "Original stack: ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int pos, k;
    cout << "Enter the position of the first element to remove: ";
    cin >> pos;
    cout << "Enter the number of elements to remove: ";
    cin >> k;
    stack<int> temp2;
    for (int i = 1; i <= n; i++) {
        if (i < pos || i >= pos + k) {
            temp2.push(st.top());
        }
        st.pop();
    }
    while (!temp2.empty()) {
        st.push(temp2.top());
        temp2.pop();
    }

    cout << "Stack after removing elements: ";
    temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int key, newKey;
    cout << "Enter the key of the element to add before: ";
    cin >> key;
    cout << "Enter the new key: ";
    cin >> newKey;
    stack<int> temp3;
    while (!st.empty()) {
        if (st.top() == key) {
            temp3.push(newKey);
        }
        temp3.push(st.top());
        st.pop();
    }
    while (!temp3.empty()) {
        st.push(temp3.top());
        temp3.pop();
    }

    cout << "Final stack: ";
    temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
