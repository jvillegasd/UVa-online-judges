#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int n;
    char input[20]; 
    scanf("%d", &n);
    cin.get();
    while(n--){
        scanf("%s", &input);
        sort(input, input + strlen(input));
        do{
            printf("%s\n", input);
        } while(next_permutation(input, input + strlen(input)));
        printf("\n");
    }
    return 0;
}