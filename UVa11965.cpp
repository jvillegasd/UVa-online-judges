#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int t, n, cont = 0;
    scanf("%d", &t);
    while(cont < t){
        printf("Case %d:\n", cont + 1);
        scanf("%d", &n);
        cin.get();
        while(n--){
            getline(cin, input);
            if(input.size() > 0) printf("%c", input[0]);
            for(int i = 1; input[i]; i++){
                if(input[i] != ' '){
                    printf("%c", input[i]);
                }else{
                    if(input[i] != input[i - 1])printf("%c", input[i]);
                }
            }
            printf("\n");
        }
        if(cont < t - 1) printf("\n");
        cont++;
    }
    return 0;
}