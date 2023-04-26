#include <iostream>
#include <vector>

using namespace std;

class Time {
public:
    Time(int minutes = 0, int seconds = 0) : minutes_(minutes), seconds_(seconds) {}
    void setMinutes(int minutes) { minutes_ = minutes; }
    void setSeconds(int seconds) { seconds_ = seconds; }
    int getMinutes() const { return minutes_; }
    int getSeconds() const { return seconds_; }
private:
    int minutes_;
    int seconds_;
};

void inputVector(vector<int>& v) {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> v[i];
    }
}

void inputTime(Time& t) {
    int m, s;
    cout << "Enter minutes: ";
    cin >> m;
    cout << "Enter seconds: ";
    cin >> s;
    t = Time(m, s);
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printTime(const Time& t) {
    cout << t.getMinutes() << ":" << t.getSeconds() << endl;
}

class VectorInt {
public:
    VectorInt() {}
    VectorInt(int size) : elements_(size) {}
    VectorInt(const VectorInt& other) : elements_(other.elements_) {}
    ~VectorInt() {}

    void input() {
        inputVector(elements_);
    }

    void print() const {
        printVector(elements_);
    }

    int operator[](int index) const {
        return elements_[index];
    }

    int& operator[](int index) {
        return elements_[index];
    }

    VectorInt operator+(const VectorInt& other) const {
        VectorInt result(elements_.size());
        for (int i = 0; i < elements_.size(); i++) {
            result[i] = elements_[i] + other[i];
        }
        return result;
    }

    friend VectorInt operator+(const VectorInt& v, int value) {
        VectorInt result(v.elements_.size());
        for (int i = 0; i < v.elements_.size(); i++) {
            result[i] = v.elements_[i] + value;
        }
        return result;
    }

    VectorInt& operator=(const VectorInt& other) {
        elements_ = other.elements_;
        return *this;
    }

private:
    vector<int> elements_;
};

int main() {
    VectorInt v1, v2;
    cout << "Enter the first vector:" << endl;
    v1.input();
    cout << "Enter the second vector:" << endl;
    v2.input();
    cout << "First vector elements: ";
    v1.print();
    cout << "Second vector elements: ";
    v2.print();

    VectorInt v3 = v1 + v2;
    cout << "Sum of vectors: ";
    v3.print();

    int value;
    cout << "Enter a value to add to the vector elements: ";
    cin >> value;
    VectorInt v4 = v1 + value;
    VectorInt v5 = v2 + value;
    cout << "Vector with added value: " << endl;
    v4.print();
    v5.print();

    Time t1, t2;
    cout << "Enter the first time interval:" << endl;

    inputTime(t1);

    cout << "Enter the second time interval:" << endl;

    inputTime(t2);

    cout << "First time interval: ";

    printTime(t1);

    cout << "Second time interval: ";

    printTime(t2);

    int totalSeconds1 = t1.getMinutes() * 60 + t1.getSeconds();

    int totalSeconds2 = t2.getMinutes() * 60 + t2.getSeconds();

    int totalSecondsSum = totalSeconds1 + totalSeconds2;

    int minutesSum = totalSecondsSum / 60;

    int secondsSum = totalSecondsSum % 60;

    Time t3(minutesSum, secondsSum);

    cout << "Sum of time intervals: ";

    printTime(t3);

    return 0;
}

