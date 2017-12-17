#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    char input[1000010];
    int n, a, b, tc = 1;
    bool valid;
    while(scanf("%s %d", &input, &n) == 2){
        printf("Case %d:\n", tc);
        tc++;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a, &b);
            if(a > b) swap(a, b);
            valid = true;
            for(int i = a; i < b && valid; i++){
                if(input[i] != input[i + 1]) valid = false;
            }
            if(valid) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}