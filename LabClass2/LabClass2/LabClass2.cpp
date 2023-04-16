#include <iostream>
#include <string>

using namespace std;

class Route {
private:
    string startPoint;
    string endPoint;
    float travelTime;
public:
    Route() {
        startPoint = "";
        endPoint = "";
        travelTime = 0.0;
    }
    Route(string start, string end, float time) {
        startPoint = start;
        endPoint = end;
        travelTime = time;
    }
    Route(const Route& other) {
        startPoint = other.startPoint;
        endPoint = other.endPoint;
        travelTime = other.travelTime;
    }
    ~Route() {
        cout << "Route object destroyed" << endl;
    }
    string getStartPoint() const {
        return startPoint;
    }
    string getEndPoint() const {
        return endPoint;
    }
    float getTravelTime() const {
        return travelTime;
    }
    void setStartPoint(string start) {
        startPoint = start;
    }
    void setEndPoint(string end) {
        endPoint = end;
    }
    void setTravelTime(float time) {
        travelTime = time;
    }
};

int main() {
    setlocale(0, "en_US.UTF-8");
    Route route1;
    route1.setStartPoint("Moscow");
    route1.setEndPoint("Saint Petersburg");
    route1.setTravelTime(5.5);
    cout << "Route 1: " << route1.getStartPoint() << " - " << route1.getEndPoint() << ", travel time: " << route1.getTravelTime() << endl;

    Route route2("Kazan", "Yekaterinburg", 3.5);
    cout << "Route 2: " << route2.getStartPoint() << " - " << route2.getEndPoint() << ", travel time: " << route2.getTravelTime() << endl;

    Route route3 = route1;
    cout << "Route 3 (copy of Route 1): " << route3.getStartPoint() << " - " << route3.getEndPoint() << ", travel time: " << route3.getTravelTime() << endl;

    return 0;
}
