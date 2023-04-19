#include <iostream>
#include <cmath>
using namespace std;

class PAIR {
protected:
    int first, second;
public:
    PAIR() : first(0), second(0) {}
    PAIR(int f, int s) : first(f), second(s) {}
    PAIR(const PAIR& p) : first(p.first), second(p.second) {}
    ~PAIR() {}

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }

    void setFirst(int f) {
        first = f;
    }

    void setSecond(int s) {
        second = s;
    }

    int getMultiplication() const {
        return first * second;
    }
};

class RIGHTANGLED : public PAIR {
public:
    RIGHTANGLED() : PAIR() {}
    RIGHTANGLED(int f, int s) : PAIR(f, s) {}
    RIGHTANGLED(const PAIR& p) : PAIR(p) {}

    double getHypotenuse() const {
        return sqrt(first * first + second * second);
    }
};

int main() {
    int f, s;
    cout << "Enter two numbers: ";
    cin >> f >> s;

    PAIR pair(f, s);
    cout << "First number: " << pair.getFirst() << ", second number: " << pair.getSecond() << ", multiplication: " << pair.getMultiplication() << endl;

    RIGHTANGLED rightangled(f, s);
    cout << "Cathetus: " << rightangled.getFirst() << ", " << rightangled.getSecond() << ", hypotenuse: " << rightangled.getHypotenuse() << endl;

    return 0;
}
