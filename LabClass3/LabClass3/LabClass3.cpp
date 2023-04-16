#include <iostream>

class Time {
private:
    int minutes;
    int seconds;
public:
    Time() : minutes(0), seconds(0) {}
    Time(int min, int sec) : minutes(min), seconds(sec) {}
    Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}

    ~Time() {}

    int getMinutes() const {
        return minutes;
    }
    void setMinutes(int min) {
        minutes = min;
    }
    int getSeconds() const {
        return seconds;
    }
    void setSeconds(int sec) {
        seconds = sec;
    }

    Time& operator=(const Time& t) {
        minutes = t.minutes;
        seconds = t.seconds;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& t) {
        out << t.minutes << ":" << t.seconds;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Time& t) {
        in >> t.minutes >> t.seconds;
        return in;
    }

    Time operator+(const int& sec) const {
        Time result = *this;
        result.addSeconds(sec);
        return result;
    }
    Time operator-(const int& sec) const {
        Time result = *this;
        result.subtractSeconds(sec);
        return result;
    }

    void addSeconds(int sec) {
        int totalSeconds = minutes * 60 + seconds + sec;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }
    void subtractSeconds(int sec) {
        int totalSeconds = minutes * 60 + seconds - sec;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

};

int main() {
    Time t1(3, 30);
    std::cout << t1 << std::endl;

    Time t2;
    std::cout << "Enter time: ";
    std::cin >> t2;
    std::cout << "You entered time: " << t2 << std::endl;

    Time t3 = t1 + 45;
    std::cout << "t1 + 45 seconds = " << t3 << std::endl;

    Time t4 = t2 - 20;
    std::cout << "t2 - 20 seconds = " << t4 << std::endl;

    return 0;
}
