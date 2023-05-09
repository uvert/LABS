#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class Time {
public:
    int minutes;
    int seconds;

    Time(int m, int s) : minutes(m), seconds(s) {}

    void addSeconds(int s) {
        seconds += s;
        minutes += seconds / 60;
        seconds %= 60;
    }

    void substractSeconds(int s) {
        seconds -= s;
        if (seconds < 0) {
            minutes--;
            seconds += 60;
        }
    }

    bool operator<(const Time& other) const {
        return (minutes < other.minutes) || (minutes == other.minutes && seconds < other.seconds);
    }

    bool operator==(const Time& other) const {
        return (minutes == other.minutes && seconds == other.seconds);
    }

    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.minutes << ":" << t.seconds;
        return os;
    }
};

int main() {
    deque<Time> times;

    // заполнение контейнера элементами
    times.push_back(Time(1, 30));
    times.push_back(Time(2, 0));
    times.push_back(Time(0, 45));
    times.push_back(Time(1, 0));
    times.push_back(Time(0, 15));

    // добавление секунд
    for_each(times.begin(), times.end(), [](Time& t) { t.addSeconds(15); });

    // вычитание секунд
    for_each(times.begin(), times.end(), [](Time& t) { t.substractSeconds(30); });

    // замена элемента с заданным ключом на заданной позиции
    replace_if(times.begin(), times.end(), [](const Time& t) { return t == Time(0, 45); }, Time(3, 30));

    // удаление элемента с заданным ключом
    times.erase(remove_if(times.begin(), times.end(), [](const Time& t) { return t == Time(2, 0); }), times.end());

    // сортировка по возрастанию
    sort(times.begin(), times.end());

    // сортировка по убыванию
    sort(times.rbegin(), times.rend());

    // поиск элемента
    auto it = find_if(times.begin(), times.end(), [](const Time& t) { return t == Time(3, 30); });
    if (it != times.end()) {
        cout << "Found: " << *it << endl;
    }

    // количество элементов
    cout << "Count: " << count_if(times.begin(), times.end(), [](const Time& t) { return t.minutes == 1; }) << endl;

    // разница между максимальным и минимальным элементами
    auto max_it = max_element(times.begin(), times.end());
    auto min_it = min_element(times.begin(), times.end());
    int diff = max_it->minutes * 60 + max_it->seconds - min_it->minutes * 60 - min_it->seconds;
    for each (Time & t : times) {
        int total_seconds = t.minutes * 60 + t.seconds;
        total_seconds -= diff;
        t.minutes = total_seconds / 60;
        t.seconds = total_seconds % 60;
    }
    // выводим элементы контейнера после изменений
    for (const Time& t : times) {
        cout << t << endl;
    }

    return 0;
}
