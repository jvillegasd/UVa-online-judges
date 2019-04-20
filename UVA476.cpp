#include <bits/stdc++.h>

using namespace std;

int main(){
    double x, y, xo[11], xf[11], yo[11], yf[11];
    int n = 0, cont = 0, flag = 0;
    char type;
    while(scanf("%c", &type) && type != '*'){
        if(type != 'r') continue;
        scanf("%lf %lf %lf %lf", &xo[n], &yo[n], &xf[n], &yf[n]);
        n++;
    }
    while(scanf("%lf %lf", &x, &y) && !(x == 9999.9 && y == 9999.9)){
        flag = 0;
        cont++;
        for(int i = 0; i < n; i++){
            if(x > xo[i] && x < xf[i] && yo[i] > y && y > yf[i]) printf("Point %d is contained in figure %d\n", cont, i + 1), flag++;
        }
        if(!flag) printf("Point %d is not contained in any figure\n", cont);
    }
    return 0;
}