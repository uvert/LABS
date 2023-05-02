#include <iostream>

using namespace std;

class Time {
public:
    int minutes;
    int seconds;

    Time(int m, int s) {
        minutes = m;
        seconds = s;
    }

    void print() {
        cout << minutes << ":" << seconds << endl;
    }

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (seconds < 0) {
            minutes += (seconds - 59) / 60;
            seconds = 60 + (seconds % 60);
        }
        if (minutes < 0) {
            minutes = 0;
            seconds = 0;
        }
    }

    bool operator==(const Time& other) const {
        return minutes == other.minutes && seconds == other.seconds;
    }

    Time operator-(const Time& other) const {
        int s = seconds - other.seconds;
        int m = minutes - other.minutes;
        return { m, s };
    }

    Time& operator-=(const Time& other) {
        minutes -= other.minutes;
        seconds -= other.seconds;
        normalize();
        return *this;
    }

    Time operator+(const Time& other) const {
        int s = seconds + other.seconds;
        int m = minutes + other.minutes;
        return { m, s };
    }

    Time& operator+=(const Time& other) {
        minutes += other.minutes;
        seconds += other.seconds;
        normalize();
        return *this;
    }
};

void deleteEntries(Time entries[], int& count, Time target) {
    int i = 0;
    while (i < count) { 
        if (entries[i] == target) {
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            count--;
        }
        else {
            i++;
        }
    }
}

void decreaseEntries(Time entries[], int count, Time target) {
    for (int i = 0; i < count; i++) {
        if (entries[i] == target) {
            entries[i] -= {1, 30}; // Вычитание интервала {1, 30}
            entries[i].normalize(); // Нормализация интервала
        }
    }
}

void insertEntries(Time entries[], int& count, Time target, Time newEntries[], int newCount) {
    for (int i = 0; i < count; i++) {
        if (entries[i] == target) {
            // Расширение массива на количество новых элементов
            for (int j = count - 1; j >= i + 1; j--) {
                entries[j + newCount] = entries[j];
            }
            // Вставка новых элементов
            for (int j = 0; j < newCount; j++) {
                entries[i + j + 1] = newEntries[j];
            }
            count += newCount;
            i += newCount; // Пропускаем вставленные элементы
        }
    }
}

int main() {
    const int MAX_ENTRIES = 10;
    Time entries[MAX_ENTRIES] = { {2, 15}, {0, 45}, {1, 30}, {2, 0}, {1, 45}, {0, 30}, {1, 0}, {2, 45}, {0, 15}, {2, 30} };
    int count = 10;
    cout << "Initial entries: " << endl;
    for (int i = 0; i < count; i++) {
        entries[i].print();
    }

    Time target = { 1, 30 };
    cout << endl << "Deleting entries equal to ";
    target.print();
    deleteEntries(entries, count, target);
    cout << "Entries after deletion: " << endl;
    for (int i = 0; i < count; i++) {
        entries[i].print();
    }

    target = { 2, 0 };
    cout << endl << "Decreasing entries equal to ";
    target.print();
    decreaseEntries(entries, count, target);
    cout << "Entries after decrease: " << endl;
    for (int i = 0; i < count; i++) {
        entries[i].print();
    }
    return 0;
}

    
