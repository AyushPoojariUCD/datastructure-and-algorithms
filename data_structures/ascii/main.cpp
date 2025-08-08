#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. ASCII Table
    cout << "=== ASCII TABLE (0-127) ===\n";
    for (int i = 0; i < 128; i++) {
        cout << setw(3) << i << " -> ";
        if (isprint(i)) cout << "'" << char(i) << "'";
        else cout << "non-printable";
        cout << "\n";
    }
    cout << "\n";

    // 2. Case Conversion
    char upper = 'B', lower = 'm';
    cout << "Upper to lower (B -> b): " << char(upper + 32) << "\n";
    cout << "Lower to upper (m -> M): " << char(lower - 32) << "\n";
    cout << "Toggle case (B -> b): " << char(upper ^ 32) << "\n";
    cout << "Toggle case (m -> M): " << char(lower ^ 32) << "\n\n";

    // 3. Digit ↔ Integer
    char digitChar = '7';
    int digitInt = 5;
    cout << "Char '7' to int: " << (digitChar - '0') << "\n";
    cout << "Int 5 to char: '" << char(digitInt + '0') << "'\n\n";

    // 4. Checks
    char ch = 'G';
    cout << ch << " is uppercase? " << (('A' <= ch && ch <= 'Z') ? "yes" : "no") << "\n";
    cout << ch << " is lowercase? " << (('a' <= ch && ch <= 'z') ? "yes" : "no") << "\n";
    cout << ch << " is digit? " << (('0' <= ch && ch <= '9') ? "yes" : "no") << "\n\n";

    // 5. Alphabet Index
    cout << "'C' index from 'A': " << ('C' - 'A') << "\n";
    cout << "'f' index from 'a': " << ('f' - 'a') << "\n\n";

    // 6. Wrap-around Shift (Caesar Cipher)
    char c1 = 'Y', c2 = 'x';
    int k = 5;
    char shiftedUpper = 'A' + ((c1 - 'A' + k) % 26);
    char shiftedLower = 'a' + ((c2 - 'a' + k) % 26);
    cout << "Shift 'Y' by 5: " << shiftedUpper << "\n";
    cout << "Shift 'x' by 5: " << shiftedLower << "\n\n";

    // 7. Bitwise Tricks
    char bitChar = 'D';
    cout << "Force lowercase (D -> d): " << char(bitChar | 32) << "\n";
    cout << "Force uppercase (d -> D): " << char('d' & ~32) << "\n";
    cout << "Same letter ignoring case? (A & a): "
         << ((( 'A' | 32) == ('a' | 32)) ? "yes" : "no") << "\n";

    return 0;
}
