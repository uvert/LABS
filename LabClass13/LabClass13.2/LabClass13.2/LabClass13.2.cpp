#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class Time {
public:
    int minutes;
    int seconds;

public:
    Time(int m = 0, int s = 0) : minutes(m), seconds(s) {}

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }

    void setMinutes(int m) {
        minutes = m;
    }

    void setSeconds(int s) {
        seconds = s;
    }

    void addSeconds(int s) {
        minutes += s / 60;
        seconds += s % 60;
        if (seconds >= 60) {
            minutes++;
            seconds -= 60;
        }
    }

    void subSeconds(int s) {
        minutes -= s / 60;
        seconds -= s % 60;
        if (seconds < 0) {
            minutes--;
            seconds += 60;
        }
    }

    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.minutes << ":" << t.seconds;
        return os;
    }

    bool operator<(const Time& other) const {
        return minutes < other.minutes || (minutes == other.minutes && seconds < other.seconds);
    }

    bool operator>(const Time& other) const {
        return minutes > other.minutes || (minutes == other.minutes && seconds > other.seconds);
    }

    bool operator==(const Time& other) const {
        return minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }
};

class TimePriorityQueue {
private:
    priority_queue<Time, vector<Time>, greater<Time>> pq;

public:
    bool empty() const {
        return pq.empty();
    }

    size_t size() const {
        return pq.size();
    }

    void push(const Time& t) {
        pq.push(t);
    }

    void pop() {
        pq.pop();
    }

    Time& top() {
        return pq.top();
    }

    const Time& top() const {
        return pq.top();
    }

    friend ostream& operator<<(ostream& os, const TimePriorityQueue& q) {
        for (auto t : q.pq) {
            os << t << " ";
        }
        return os;
    }
};

int main() {
    Time t1(2, 30);
    Time t2(1, 45);
    Time t3(3, 15);

    TimePriorityQueue q;
    q.push(t1);
    q.push(t2);
    q.push(t3);

    // добавление/вычитание секунд
    t1.addSeconds(15);
    t2.subSeconds(30);

    // замена элемента с заданным ключом
    replace(q.pq.begin(), q.pq.end(), t1, t2); // заменяем t1 на t2
    replace_if(q.pq.begin(), q.pq.end(), [](const Time& t) { return t.getMinutes() > 2; }, Time(4, 30)); // заменяем все элементы с минутами > 2 на 4:30
    replace_copy(q.pq.begin(), q.pq.end(), ostream_iterator<Time>(cout, " "), t2, t1); // копируем все элементы, заменяя t2 на t1
    fill(q.pq.begin(), q.pq.end(), Time(0, 0));
    // удаление элемента с заданным ключом
    q.pq.erase(remove(q.pq.begin(), q.pq.end(), t1), q.pq.end()); // удаляем все элементы, равные t1
    q.pq.erase(remove_if(q.pq.begin(), q.pq.end(), [](const Time& t) { return t.getSeconds() > 30; }), q.pq.end()); // удаляем все элементы, у которых секунды > 30
    remove_copy(q.pq.begin(), q.pq.end(), ostream_iterator<Time>(cout, " "), t1); // копируем все элементы, исключая t1
    remove_copy_if(q.pq.begin(), q.pq.end(), ostream_iterator<Time>(cout, " "), [](const Time& t) { return t.getMinutes() > 2; }); // копируем все элементы, исключая те, у которых минуты > 2

    // сортировка контейнера
    sort(q.pq.begin(), q.pq.end()); // сортировка по возрастанию
    sort(q.pq.begin(), q.pq.end(), greater<Time>()); // сортировка по убыванию

    // поиск элемента в контейнере
    auto it = find(q.pq.begin(), q.pq.end(), t1); // поиск t1 в очереди
    int count = count(q.pq.begin(), q.pq.end(), t1); // количество элементов, равных t1
    auto it_if = find_if(q.pq.begin(), q.pq.end(), [](const Time& t) { return t.getSeconds() == 45; }); // поиск первого элемента, у которого секунды = 45
    int count_if = count_if(q.pq.begin(), q.pq.end(), [](const Time& t) { return t.getMinutes() > 2; }); // количество элементов, у которых минуты > 2

    // изменение элементов контейнера
    int diff = q.pq.back().getSeconds() - q.pq.front().getSeconds(); // разница между максимальным и минимальным элементами
    for_each(q.pq.begin(), q.pq.end(), [diff](Time& t) { t.subSeconds(diff); }); // вычитаем разницу из каждого элемента

    return 0;
}
