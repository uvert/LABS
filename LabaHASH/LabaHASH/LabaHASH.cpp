#include <iostream>
#include <string>
#include <random>
#include <unordered_map>

using namespace std;

struct Record {
    string name;
    string phone;
    string address;
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> char_dist(97, 122);
    uniform_int_distribution<> phone_dist(1000000, 9999999);
    uniform_int_distribution<> addr_dist(1, 100);

    const int size = 100;
    Record* records = new Record[size];
    for (int i = 0; i < size; ++i) {
        string name = "";
        for (int j = 0; j < 10; ++j) {
            name += static_cast<char>(char_dist(gen));
        }
        string phone = to_string(phone_dist(gen));
        string address = "Street " + to_string(addr_dist(gen));

        records[i] = { name, phone, address };
    }

    for (int i = 0; i < size; ++i) {
        cout << "Record #" << i << ": " << records[i].name << ", "
            << records[i].phone << ", " << records[i].address << endl;
    }

    int table_size = 40;
    unordered_map<string, Record*> table(table_size);
    int collisions = 0;
    for (int i = 0; i < size; ++i) {
        auto result = table.emplace(records[i].name, &records[i]);
        if (!result.second) {
            ++collisions;
        }
    }
    cout << "Collisions with " << table_size << " table size: " << collisions << endl;

    table_size = 75;
    table = unordered_map<string, Record*>(table_size);
    collisions = 0;
    for (int i = 0; i < size; ++i) {
        auto result = table.emplace(records[i].name, &records[i]);
        if (!result.second) {
            ++collisions;
        }
    }
    cout << "Collisions with " << table_size << " table size: " << collisions << endl;

    table_size = 90;
    table = unordered_map<string, Record*>(table_size);
    collisions = 0;
    for (int i = 0; i < size; ++i) {
        auto result = table.emplace(records[i].name, &records[i]);
        if (!result.second) {
            ++collisions;
        }
    }
    cout << "Collisions with " << table_size << " table size: " << collisions << endl;

    string name;
    cout << "Enter name to search: ";
    cin >> name;

    auto it = table.find(name);
    if (it != table.end()) {
        cout << "Record found: " << it->second->name << ", "
            << it->second->phone << ", " << it->second->address << endl;
    }
    else {
        cout << "Record not found." << endl;
    }

    delete[] records;

    return 0;
}
