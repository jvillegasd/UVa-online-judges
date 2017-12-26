#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string input;
    while(getline(cin, input) && input != "#"){
        if(next_permutation(input.begin(), input.end())) cout << input << "\n";
        else printf("No Successor\n");
    }   
    return 0;
}