#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n, max;
    string input;
    scanf("%d", &n);
    cin.get();
    while(n--){
        map<char, int> freq;
        getline(cin, input);
        for(int i = 0; input[i]; i++){
            if(input[i] >= 'a' && input[i] <= 'z') freq[input[i]]+=1;
            else if(input[i] >= 'A' && input[i] <= 'Z') freq[input[i] + 32]+=1;
        }
        max = -1;
        for(auto iterator = freq.begin(); iterator != freq.end(); iterator++){
            if(iterator->second > max) max = iterator->second;
        }
        for(auto iterator = freq.begin(); iterator != freq.end(); iterator++){
            if(iterator->second == max) printf("%c", iterator->first);
        }
        printf("\n");
    }
    return 0;
}
// Otro problema del tipo de guardar la frecuencia en que aparece una letra...
