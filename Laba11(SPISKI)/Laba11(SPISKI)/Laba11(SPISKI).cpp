#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

void deleteElements(Node*& head, int start, int k) {
    if (head == nullptr) return;

    Node* prev = nullptr;
    Node* curr = head;
    int count = 1;
    while (curr != nullptr && count < start) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    int deleteCount = 0;
    while (curr != nullptr && deleteCount < k) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
        deleteCount++;
    }

    if (prev == nullptr) {
        head = curr;
    }
    else {
        prev->next = curr;
    }
}

void addBefore(Node*& head, int key, int newKey) {
    if (head == nullptr) return;

    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->next = curr;
    if (prev == nullptr) {
        head = newNode;
    }
    else {
        prev->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter the number of items in the list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        cout << "Enter key for element: " << i + 1 << ": ";
        cin >> key;
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = head;
        head = newNode;
    }

    cout << "Source List: ";
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << endl;

    int start, k;
    cout << "Enter the element number from which you want to delete elements: ";
    cin >> start;
    cout << "Enter the number of items to be removed: ";
    cin >> k;
    deleteElements(head, start, k);

    cout << "List after elements removed: ";
    curr = head;
    while (curr != nullptr) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << endl;

    int key, newKey;
    cout << "Enter the element key before which you want to add the new element: ";
    cin >> key;
    cout << "Enter a new key: ";
    cin >> newKey;
    addBefore(head, key, newKey);

    cout << "Final list: ";
    curr = head;
    while (curr != nullptr) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

