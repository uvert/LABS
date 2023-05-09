#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Time {
public:
    Time(int minutes = 0, int seconds = 0) {
        set(minutes, seconds);
    }

    void set(int minutes, int seconds) {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        minutes_ = minutes;
        seconds_ = seconds;
    }

    void addSeconds(int seconds) {
        set(minutes_, seconds_ + seconds);
    }

    void subtractSeconds(int seconds) {
        set(minutes_, seconds_ - seconds);
    }

    int minutes() const {
        return minutes_;
    }

    int seconds() const {
        return seconds_;
    }

private:
    int minutes_;
    int seconds_;
};

bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.minutes() == rhs.minutes() && lhs.seconds() == rhs.seconds();
}

bool operator!=(const Time& lhs, const Time& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs) {
    if (lhs.minutes() < rhs.minutes()) {
        return true;
    }
    else if (lhs.minutes() == rhs.minutes() && lhs.seconds() < rhs.seconds()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const Time& lhs, const Time& rhs) {
    return rhs < lhs;
}

bool operator<=(const Time& lhs, const Time& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Time& lhs, const Time& rhs) {
    return !(lhs < rhs);
}

Time operator+(const Time& lhs, const Time& rhs) {
    int minutes = lhs.minutes() + rhs.minutes();
    int seconds = lhs.seconds() + rhs.seconds();
    return Time(minutes, seconds);
}

Time operator-(const Time& lhs, const Time& rhs) {
    int minutes = lhs.minutes() - rhs.minutes();
    int seconds = lhs.seconds() - rhs.seconds();
    return Time(minutes, seconds);
}

ostream& operator<<(ostream& os, const Time& t) {
    os << t.minutes() << ":" << t.seconds();
    return os;
}

istream& operator>>(istream& is, Time& t) {
    int minutes, seconds;
    is >> minutes >> seconds;
    t.set(minutes, seconds);
    return is;
}

vector<Time> createVector(int count) {
    vector<Time> myVector;
    for (int i = 0; i < count; i++) {
        int minutes, seconds;
        cout << "Enter minutes and seconds for element #" << i + 1 << ": ";
        cin >> minutes >> seconds;
        myVector.push_back(Time(minutes, seconds));
    }
    return myVector;
}

void insertByKey(vector<Time>& myVector, const Time& key, int pos) {
    auto it = find(myVector.begin(), myVector.end(), key);
    if (it != myVector.end()) {
        myVector.insert(myVector.begin() + pos, *it);
    }
}

void eraseByKey(vector<Time>& myVector, const Time& key) {
    auto it = find(myVector.begin(), myVector.end(), key);
    if (it != myVector.end()) {
        myVector.erase(it);
    }
}

void subtractMinMax(vector<Time>& myVector) {
    auto minmax = minmax_element(myVector.begin(), myVector.end());
    Time diff = *(minmax.second) - *(minmax.first);

    for (auto& elem : myVector) {
        elem = elem - diff;
    }
}

int main() {
    int count;
    cout << "Enter the number of elements to enter: ";
    cin >> count;
    vector<Time> myVector = createVector(count);

    cout << "Vector elements: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    int addSeconds;
    cout << "Enter the number of seconds to add to all elements: ";
    cin >> addSeconds;

    for (auto& elem : myVector) {
        elem.addSeconds(addSeconds);
    }

    cout << "Vector elements after adding " << addSeconds << " seconds: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    int subtractSeconds;
    cout << "Enter the number of seconds to subtract from all elements: ";
    cin >> subtractSeconds;

    for (auto& elem : myVector) {
        elem.subtractSeconds(subtractSeconds);
    }

    cout << "Vector elements after subtracting " << subtractSeconds << " seconds: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    Time key;
    cout << "Enter minutes and seconds for key element: ";
    cin >> key;

    int pos;
    cout << "Enter position to insert key element: ";
    cin >> pos;

    insertByKey(myVector, key, pos);

    cout << "Vector elements after inserting key element: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    eraseByKey(myVector, key);

    cout << "Vector elements after erasing key element: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    subtractMinMax(myVector);

    cout << "Vector elements after subtracting difference between min and max element: ";
    for (const auto& elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
