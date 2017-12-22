#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int n, cont;
    scanf("%d", &n);
    cin.get();
    while(n--){
        char input[200];
        scanf("%s", &input);
        if(strlen(input) == 3){
            cont = 0;
            if(input[0] == 'o') cont++;
            if(input[1] == 'n') cont++;
            if(input[2] == 'e') cont++;
            if(cont >= 2) printf("1\n");
            else printf("2\n");
        }else printf("3\n");
    }
    return 0;
}