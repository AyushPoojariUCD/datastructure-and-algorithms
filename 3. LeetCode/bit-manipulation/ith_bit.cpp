#include <iostream>
using namespace std;

int main() {
    int n = 5;  // 0101
    int i = 1;  // position of bit to operate on

    int mask = (1 << i); // step 1: create mask

    // --- Set bit ---
    int setNum = n | mask;  // 0101 | 0010 = 0111 (7)
    cout << "After setting bit " << i << ": " << setNum << endl;

    // --- Clear bit ---
    int clearNum = n & (~mask); // 0101 & 1101 = 0101 (still 5)
    cout << "After clearing bit " << i << ": " << clearNum << endl;

    // --- Toggle bit ---
    int toggleNum = n ^ mask; // 0101 ^ 0010 = 0111 (7)
    cout << "After toggling bit " << i << ": " << toggleNum << endl;

    // --- Check bit ---
    bool isSet = (n & mask) != 0;
    cout << "Is bit " << i << " set? " << (isSet ? "Yes" : "No") << endl;

    return 0;
}
