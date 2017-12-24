#include <stdio.h>
#include <sstream>

using namespace std;

int main(){
    int t, cont = 0, index;
    char input[1200];
    scanf("%d ", &t);
    while(cont < t){
        printf("Case #%d:\n", cont + 1);
        while(gets(input)){
            if(input[0] == '\0') break;
            stringstream ss(input);
            string word;
            index = 1;
            while(ss >> word){
                if(word.size() < index) continue;
                printf("%c", word[index - 1]);
                index++;
            }
            printf("\n");
        }
        cont++;
        if(cont < t) printf("\n");
    }
    return 0;
}