#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc, xo1, yo1, x1, y1, xo2, yo2, x2, y2, i, j, k, l;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d %d %d %d %d %d %d", &xo1, &yo1, &x1, &y1, &xo2, &yo2, &x2, &y2);
        i = max(xo1, xo2);
        j = max(yo1, yo2);
        k = min(x1, x2);
        l = min(y1, y2);
        if(i >= k || j >= l) printf("No Overlap\n");
        else printf("%d %d %d %d\n", i, j, k, l);
        if(tc) printf("\n");
    }
    return 0;
}