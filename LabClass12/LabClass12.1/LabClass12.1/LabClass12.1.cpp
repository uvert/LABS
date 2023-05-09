#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Create a multiset with elements of type double
multiset<double> createSet()
{
    multiset<double> set;

    // Fill the set
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        double element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        set.insert(element);
    }

    return set;
}

// Find the element with the given key and insert it at the specified position
void insertElement(multiset<double>& set, double key, int position)
{
    // Find the element with the given key
    auto it = set.find(key);

    if (it == set.end())
    {
        cout << "Element not found." << endl;
        return;
    }

    // Insert the element at the specified position
    auto insertIt = next(set.begin(), position - 1);
    set.insert(insertIt, *it);
}

// Find the element with the given key and remove it from the set
void removeElement(multiset<double>& set, double key)
{
    // Find the element with the given key
    auto it = set.find(key);

    if (it == set.end())
    {
        cout << "Element not found." << endl;
        return;
    }

    // Remove the element
    set.erase(it);
}

// Find the difference between the maximum and minimum elements and subtract it from each element
void subtractMinMax(multiset<double>& set)
{
    // Find the minimum and maximum elements
    auto minIt = min_element(set.begin(), set.end());
    auto maxIt = max_element(set.begin(), set.end());

    double diff = *maxIt - *minIt;

    // Subtract the difference from each element
    for (auto& element : set)
    {
        element == diff;
    }
}

int main()
{
    multiset<double> set = createSet();

    // Print the initial set
    cout << "Initial set: ";
    for (auto& element : set)
    {
        cout << element << " ";
    }
    cout << endl;

    // Find the element with the given key and insert it at the specified position
    double key;
    int position;

    cout << "Enter the key of the element to add: ";
    cin >> key;

    cout << "Enter the position to add the element: ";
    cin >> position;

    insertElement(set, key, position);

    // Print the modified set
    cout << "Set after inserting an element: ";
    for (auto& element : set)
    {
        cout << element << " ";
    }
    cout << endl;

    // Find the element with the given key and remove it from the set
    cout << "Enter the key of the element to remove: ";
    cin >> key;

    removeElement(set, key);

    // Print the modified set
    cout << "Set after removing an element: ";
    for (auto& element : set)
    {
        cout << element << " ";
    }
    cout << endl;

    // Find the difference between the maximum and minimum elements and subtract it from each element
    subtractMinMax(set);

    // Print the modified set
    cout << "Set after subtracting the difference between the maximum and minimum elements: ";
    for (auto& element : set)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}