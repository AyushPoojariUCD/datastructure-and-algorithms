#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void countVowelConsonants(string &s){
    int vowel = 0, consonants = 0;

    for(char ch : s){
        if (isalpha(ch)) {           
            if (isVowel(ch)) vowel++;
            else consonants++;
        }
    }

    cout << "Vowels: " << vowel << endl;
    cout << "Consonants: " << consonants << endl;
}

int main() {
    string s = "AbcdeIfgh";
    countVowelConsonants(s);
    return 0;
}
