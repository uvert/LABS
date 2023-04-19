#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Pair {
protected:
    int first;
    int second;
public:
    Pair(int f, int s) : first(f), second(s) {}
    virtual ~Pair() {}
    virtual void setFirst(int f) { first = f; }
    virtual void setSecond(int s) { second = s; }
    virtual int getProduct() { return first * second; }
    virtual void print() { cout << "(" << first << ", " << second << ", " << getProduct() << ")"; }
};

class RightAngledTriangle : public Pair {
public:
    RightAngledTriangle(int f, int s) : Pair(f, s) {}
    ~RightAngledTriangle() {}
    double getHypotenuse() { return sqrt(first * first + second * second); }
    void print() { Pair::print(); cout << ", hypotenuse: " << getHypotenuse(); }
};

class Vector {
private:
    vector<shared_ptr<Pair>> elements;
public:
    void add(shared_ptr<Pair> p) { elements.push_back(p); }
    void print() {
        for (auto& p : elements) {
            p->print();
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector v;

    int f, s;

    cout << "Enter the first and second cathetus of a right-angled triangle:" << endl;
    cin >> f >> s;
    shared_ptr<RightAngledTriangle> p1 = make_shared<RightAngledTriangle>(f, s);

    v.add(p1);

    v.print();


    return 0;
}