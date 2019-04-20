#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char word[550], inverse[550];
    while(gets(word) && strcmp("DONE", word) != 0){
        int index = 0, aIndex = 0;
        for(int i = 0; word[i]; i++){
            if(word[i]>='a' && word[i] <='z'){
                word[index] = word[i];
                index++; 
            }
            if(word[i]>='A' && word[i]<='Z'){
                word[index] = word[i] + 32;
                index++; 
            }
        }
        word[index] = '\0';
        for(int i = index - 1; i>= 0; i--){
            inverse[aIndex] = word[i];
            aIndex++;
        }
        inverse[aIndex] = '\0';
        if(strcmp(word, inverse) == 0) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}