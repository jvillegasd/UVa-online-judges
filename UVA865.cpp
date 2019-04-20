#include <stdio.h>

using namespace std;

int main(){ 
    char alpha[70], sust[70], line[70], ascii[128];
    int tc;
    scanf("%d", &tc);
    getchar();
	getchar();
    while(tc-- > 0){
        gets(alpha);
        gets(sust);
        printf("%s\n%s\n",sust, alpha);
        for(int i = 0; i < 128; i++) ascii[i] = i;
        for(int i = 0; alpha[i] != 0; i++) ascii[alpha[i]] = sust[i];
        while(gets(line)){
          if(line[0] == '\0') break;
            for(int i = 0; line[i] != 0; i++) printf("%c", ascii[line[i]]);
            printf("\n");
        }
        if(tc > 0) printf("\n");
    }
    return 0;
}