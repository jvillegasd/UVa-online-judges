#include <bits/stdc++.h>

using namespace std;

void day(int &dd, int &mm, int &yy){
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap = (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0);
    if(leap) month[2]++;
    dd++;
    if(dd > month[mm]) mm++, dd = 1;
    if(mm == 13) yy++, mm = dd = 1;
}

int main(){
    int n, days, sum;
    while(scanf("%d", &n) && n){
        int mm[1500], yy[1500], dd[1500], cc[1500];
        days = sum = 0;
        for(int i = 0; i < n; i++) scanf("%d %d %d %d", &dd[i], &mm[i], &yy[i], &cc[i]);
        for(int i = 0; i < n - 1; i++){
            day(dd[i], mm[i], yy[i]);
            if(dd[i] == dd[i + 1] && mm[i] == mm[i + 1] && yy[i] == yy[i + 1]) days++, sum+=(cc[i + 1] - cc[i]);
        }
        printf("%d %d\n", days, sum);
    }
    return 0;
}