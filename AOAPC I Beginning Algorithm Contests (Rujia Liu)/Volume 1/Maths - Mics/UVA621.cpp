#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int N;
    cin >> N;
    getline(cin, input); //New line
    while(N-- > 0){
        getline(cin, input);
        if(input == "1" || input == "4" || input == "78") printf("+\n");
        else if(input.substr(input.size()-2, 2) == "35") printf("-\n");
        else if(input[0] == '9' && input[input.size() - 1] == '4') printf("*\n");
        else printf("?\n");
    }
    return 0;
}