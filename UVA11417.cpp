#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int sum = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++) sum+=__gcd(i, j);
        }
        printf("%d\n", sum);
    }
    return 0;
}