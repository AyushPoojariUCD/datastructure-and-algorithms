#include<bits/stdc++.h>
using namespace std;

class Main{
    public:
        void evenOdd(int n){
            if(n&1){
                cout << "Even Number" << "->" << n;
            }else{
                cout << "Odd Number" << "->" << n;
            }
        }
}