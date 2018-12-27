#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, c;
    while(scanf("%d %d %d", &n, &m, &c) && n != 0){
        printf("%d\n", ((n - 7)*(m - 7) + c)/2);
    }
    return 0;
}