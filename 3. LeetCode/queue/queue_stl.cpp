#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);

    cout << "Front: " << q.front() << endl;  
    cout << "Back: " << q.back() << endl;    

    q.pop();
    cout << "After pop, Front: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;
}
