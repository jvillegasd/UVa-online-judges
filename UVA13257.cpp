#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int n, len;
    char input[100050];
    scanf("%d", &n);
    while(n--){
        scanf("%s", input);
        len = strlen(input);
        int post[len+1][26];
        for(int i = 0; i < 26; i++) post[len][i] = -1;
        for(int i = len - 1; i >= 0; i--){
            for(int j = 0; j < 26; j++) post[i][j] = post[i + 1][j];
            post[i][input[i] - 'A'] = i;
        }
        int result = 0;
        for(int i = 0; i < 26; i++){
            if(post[0][i] == -1) continue;
            int one = post[0][i];
            for(int j = 0; j < 26; j++){
                if(post[one + 1][j] == -1) continue;
                int two = post[one + 1][j];
                for(int k = 0; k < 26; k++){
                    if(post[two + 1][k] == -1) continue;
                    result++;
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}