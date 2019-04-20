#include <iostream>

using namespace std;

int main(){
    int v, t;
    while(true){
        cin >> v >> t;
        if(cin.fail()) break;
        cout << v*t*2 << endl;
    }
    return 0;
}