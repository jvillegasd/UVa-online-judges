#include <string>
#include <iostream>

using namespace std;

int main(){
    string input;
    while(getline(cin, input)){
        int j = 0;
        for(int i = 0; i < input.size(); i++){
            j = i;
            while(input[i] != ' ' && i < input.size()) i++;
            for(int k = i - 1; k >= j; k--) printf("%c", input[k]);
            if(i < input.size() - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}