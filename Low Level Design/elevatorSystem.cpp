#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

//==================== ENUMS ====================//

enum class Direction {
    UP,
    DOWN,
    IDLE
};

enum class ElevatorState {
    MOVING,
    IDLE
};

enum class DoorState {
    OPEN,
    CLOSED
};

//==================== REQUEST ====================//

class Request {
public:
    int sourceFloor;
    int destinationFloor;
    Direction direction;

    Request(int src, int dest)
        : sourceFloor(src), destinationFloor(dest) {

        direction = (dest > src) ? Direction::UP : Direction::DOWN;
    }
};

//==================== DOOR ====================//

class Door {
private:
    DoorState state;

public:
    Door() {
        state = DoorState::CLOSED;
    }

    void open() {
        state = DoorState::OPEN;
        cout << "Door Opened\n";
    }

    void close() {
        state = DoorState::CLOSED;
        cout << "Door Closed\n";
    }
};

//==================== DISPLAY ====================//

class Display {
public:
    void show(int floor, Direction dir) {

        cout << "Current Floor : " << floor << " ";

        if (dir == Direction::UP)
            cout << "UP";
        else if (dir == Direction::DOWN)
            cout << "DOWN";
        else
            cout << "IDLE";

        cout << endl;
    }
};

//==================== ELEVATOR ====================//

class Elevator {

private:
    int id;
    int currentFloor;

    Direction direction;
    ElevatorState state;

    Door door;
    Display display;

    queue<int> requests;

public:

    Elevator(int id) {
        this->id = id;
        currentFloor = 0;
        direction = Direction::IDLE;
        state = ElevatorState::IDLE;
    }

    int getCurrentFloor() {
        return currentFloor;
    }

    bool isIdle() {
        return state == ElevatorState::IDLE;
    }

    void addRequest(int floor) {
        requests.push(floor);
    }

    void processRequests() {

        while (!requests.empty()) {

            int destination = requests.front();
            requests.pop();

            if (destination > currentFloor)
                direction = Direction::UP;
            else if (destination < currentFloor)
                direction = Direction::DOWN;
            else
                direction = Direction::IDLE;

            state = ElevatorState::MOVING;

            while (currentFloor != destination) {

                if (direction == Direction::UP)
                    currentFloor++;
                else
                    currentFloor--;

                display.show(currentFloor, direction);
            }

            state = ElevatorState::IDLE;
            direction = Direction::IDLE;

            door.open();

            cout << "Elevator " << id
                 << " reached Floor "
                 << currentFloor << endl;

            door.close();
        }
    }
};

//==================== CONTROLLER ====================//

class ElevatorController {

private:
    vector<Elevator> elevators;

public:

    ElevatorController(int n) {

        for (int i = 0; i < n; i++)
            elevators.push_back(Elevator(i));
    }

    int findNearestElevator(int floor) {

        int index = 0;
        int minDistance = INT_MAX;

        for (int i = 0; i < elevators.size(); i++) {

            int dist = abs(elevators[i].getCurrentFloor() - floor);

            if (dist < minDistance) {

                minDistance = dist;
                index = i;
            }
        }

        return index;
    }

    void requestElevator(Request req) {

        int idx = findNearestElevator(req.sourceFloor);

        cout << "\nAssigning Elevator "
             << idx
             << endl;

        elevators[idx].addRequest(req.sourceFloor);
        elevators[idx].addRequest(req.destinationFloor);

        elevators[idx].processRequests();
    }
};

//==================== MAIN ====================//

int main() {

    ElevatorController controller(3);

    controller.requestElevator(Request(0, 5));

    controller.requestElevator(Request(3, 9));

    controller.requestElevator(Request(8, 2));

    return 0;
}