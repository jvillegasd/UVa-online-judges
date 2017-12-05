#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    string input;
    while(true){
        cin >> N;
        if(N == 0) break;
        cin >> input;
        int groups = input.size()/N;
        for(int i = 0; i < input.size(); i += groups){
            for(int j = i + groups - 1; j >= i; j--){
                printf("%c", input[j]);
            }
        }
        printf("\n");
    }
}