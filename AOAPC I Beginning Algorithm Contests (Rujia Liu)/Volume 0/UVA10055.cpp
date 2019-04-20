#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n1, n2;
    while(true){
        cin >> n1 >> n2;
        if(cin.fail()) break;
        cout << abs(n1-n2) << endl;
    }
    return 0;
}