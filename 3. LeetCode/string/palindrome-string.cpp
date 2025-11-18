#include <bits/stdc++.h>
using namespace std;

// Check Palindrome
bool isPalindrome(string &s){
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

/* Main Function */
int main() {
    string a = "malayalam";
    cout << "Palindrome(a): " << isPalindrome(a) << endl;

    string b = "ab";
    cout << "Palindrome(b): " << isPalindrome(b) << endl;

    return 0;
}
