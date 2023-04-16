#include <iostream>
using namespace std;

struct Product {
    int first;
    int second;
    void Init(int f, int s) {
        if (f < 0 || s < 0) {
            cout << "Error. Values are incorrect" << endl;
            exit(0);
        }
        first = f;
        second = s;
    }
    void Read() {
        cout << "Enter price: ";
        cin >> first;
        cout << "Enter Quantity: ";
        cin >> second;
        Init(first, second);
    }
    void Show() {
        cout << "Price - " << first << ", Quantity - " << second << endl;
    }
    int cost() {
        return first * second;
    }
};

Product make_Product(int f, int s) {
    Product pr;
    pr.Init(f, s);
    return pr;
}

int main() {
    Product p1, p2;

    p1 = make_Product(35, 50);

    cout << "Product 1: ";
    p1.Show();

    cout << "Product price 1 - " << p1.cost() << endl;

    p2.Read();
    cout << "Product 2: ";
    p2.Show();
    cout << "Product price 2 - " << p2.cost() << endl;

    return 0;
}
