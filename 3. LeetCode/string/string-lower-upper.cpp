#include<iostream>
using namespace std;

void toLower(string &s){
    for(char &ch: s){     
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + 32;  
        }
    }
}

void toUpper(string &s){
    for(char &ch: s){     
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - 32;  
        }
    }
}

int main(){
    string s = "AyUsh PoOJaRi";
    toLower(s);
    cout << "Lower: " << s << endl;
    toUpper(s);
    cout << "Upper: " << s; 
    return 0;
}