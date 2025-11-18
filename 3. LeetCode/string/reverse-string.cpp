#include<bits/stdc++.h>
using namespace std;

// Reverse String -> Recursive Approach
void reverseRec(string &s, int i, int j){
    if(i >= j) return;
    swap(s[i],s[j]);
    reverseRec(s,i + 1,j - 1);
}

// Reverse String -> Normal Approach
void reverse(string &s){
    int i = 0;
    int j = s.size() - 1;
    while(i <= j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
}

/*
Main Function
*/
int main(){
    string s = "abcdefg";
    reverse(s);
    cout << "Reverse: " << s << "\n";
    reverseRec(s,0,s.size() - 1);
    cout << "Reverse: " << s;
    return 0;
}