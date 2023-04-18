#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        cout << "Enter the key for element " << i + 1 << ": ";
        cin >> key;
        q.push(key);
    }

    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    int pos, k;
    cout << "Enter the position of the first element to remove: ";
    cin >> pos;
    cout << "Enter the number of elements to remove: ";
    cin >> k;
    queue<int> temp2;
    for (int i = 1; i <= n; i++) {
        if (i < pos || i >= pos + k) {
            temp2.push(q.front());
        }
        q.pop();
    }
    while (!temp2.empty()) {
        q.push(temp2.front());
        temp2.pop();
    }

    cout << "Queue after removing elements: ";
    temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    int key, newKey;
    cout << "Enter the key of the element to add before: ";
    cin >> key;
    cout << "Enter the new key: ";
    cin >> newKey;
    queue<int> temp3;
    while (!q.empty()) {
        if (q.front() == key) {
            temp3.push(newKey);
        }
        temp3.push(q.front());
        q.pop();
    }
    while (!temp3.empty()) {
        q.push(temp3.front());
        temp3.pop();
    }

    cout << "Final queue: ";
    temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
