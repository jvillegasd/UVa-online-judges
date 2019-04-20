#include <iostream>
#include <string>

using namespace std;

int main(){
    string input, output;
    while(true){
        cin >> input;
        output = "";
        if(cin.fail()) break;
        for(int i = 0; i < input.length(); i++) output += input[i] - 7;
        cout << output << endl;
    }
    return 0;
}