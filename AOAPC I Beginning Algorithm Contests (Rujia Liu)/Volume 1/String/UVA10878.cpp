#include <iostream>
#include <string>

using namespace std;

int main(){
    int binary[] = {256, 128, 64, 32, 16, 8, 0, 4, 2, 1};
    string line;
    while(getline(cin, line)){
        if(line[0] == '_') continue;
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            if(line[i] == 'o') ans += binary[i];
        }
        cout << (char)ans;
    }
}