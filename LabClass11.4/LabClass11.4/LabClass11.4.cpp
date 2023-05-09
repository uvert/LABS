#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
void insert_at(priority_queue<T>& pq, const T& new_value, int position)
{
    auto temp = pq;
    pq = priority_queue<T>();
    int i = 0;
    while (!temp.empty()) {
        if (i == position)
            pq.push(new_value);
        pq.push(temp.top());
        temp.pop();
        i++;
    }
    if (i == position)
        pq.push(new_value);
}

template<typename T>
void remove_value(priority_queue<T>& pq, const T& value_to_remove)
{
    auto temp = pq;
    pq = priority_queue<T>();
    while (!temp.empty()) {
        if (temp.top() != value_to_remove)
            pq.push(temp.top());
        temp.pop();
    }
}

template<typename T>
void subtract_max_min(priority_queue<T>& pq)
{
    int max_val = pq.top();
    pq.pop();
    int min_val = pq.top();
    pq.push(max_val - min_val);
}

template<typename T>
void print_queue(priority_queue<T> q)
{
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    int num_elements, key, position, value;
    cout << "Enter the number of elements to insert: ";
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        cout << "Enter element #" << i + 1 << ": ";
        cin >> value;
        pq.push(value);
    }
    cout << "Initial queue: ";
    print_queue(pq);
    cout << "Enter the key of the element to insert: ";
    cin >> key;
    cout << "Enter the position to insert the element: ";
    cin >> position;
    insert_at(pq, key, position);
    cout << "Queue after inserting element: ";
    print_queue(pq);
    cout << "Enter the key of the element to remove: ";
    cin >> key;
    remove_value(pq, key);
    cout << "Queue after removing element: ";
    print_queue(pq);
    subtract_max_min(pq);
    cout << "Final result: ";
    print_queue(pq);
    return 0;
}
