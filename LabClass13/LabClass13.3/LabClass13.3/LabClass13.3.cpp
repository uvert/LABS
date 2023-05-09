#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Определение класса Time
class Time {
public:
    int minutes;
    int seconds;

public:
    Time(int m, int s) {
        minutes = m;
        seconds = s;
        normalize();
    }

    // Перегрузка оператора сложения
    Time operator+(const Time& other) const {
        int m = minutes + other.minutes;
        int s = seconds + other.seconds;
        if (s >= 60) {
            s -= 60;
            m += 1;
        }
        return Time(m, s);
    }

    // Перегрузка оператора вычитания
    Time operator-(const Time& other) const {
        int m = minutes - other.minutes;
        int s = seconds - other.seconds;
        if (s < 0) {
            s += 60;
            m -= 1;
        }
        return Time(m, s);
    }

    // Нормализация времени (в минуте не может быть более 60 секунд)
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }

    // Перегрузка оператора вывода в поток
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << t.minutes << ":" << t.seconds;
        return out;
    }
};

int main() {
    map<int, Time> container;

    // Заполнение контейнера
    container[1] = Time(3, 40);
    container[2] = Time(2, 50);
    container[3] = Time(4, 10);

    // Добавление секунд
    container[2] = container[2] + Time(0, 30);

    // Вычитание секунд
    container[3] = container[3] - Time(0, 20);

    // Поиск элемента с заданным ключом и добавление на заданную позицию
    auto it = container.find(2);
    if (it != container.end()) {
        container.insert(container.begin(), make_pair(4, it->second));
    }

    // Удаление элемента с заданным ключом
    container.erase(3);

    // Сортировка по возрастанию ключевого поля
    map<int, Time> container_asc(container.begin(), container.end());

    // Сортировка по убыванию ключевого поля
    auto cmp = [](const auto& a, const auto& b) {
        return a.first > b.first;
    };
    map<int, Time, decltype(cmp)> container_desc(cmp);
    container_desc.insert(container.begin(), container.end());

    // Поиск элемента
    auto count = count_if(container.begin(), container.end(),
        [](const auto& p) { return p.second == Time(2, 50); });

    // Разница между максимальным и минимальным элементами и вычитание ее из каждого элемента
    auto min_max = minmax_element(container.begin(), container.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
    auto diff = min_max.second->second - min_max.first->second;
    for_each(container.begin(), container.end(), [diff](auto& p) { p.second -= diff; });

    // Вывод элементов после изменений
    cout << "Container after subtracting difference between min and max values from each element:\n";
    for (const auto& p : container) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
