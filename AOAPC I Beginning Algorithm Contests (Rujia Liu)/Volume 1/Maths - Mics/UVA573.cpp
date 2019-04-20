#include <stdio.h>

using namespace std;

int main(){
    int h, d, f, day;
    float u, factor, aH;
    while(scanf("%d %f %d %d", &h, &u, &d, &f) && h != 0){
        day = 1;
        factor = u*f/100;
        aH = 0;
        while(true){
            aH += u;
            if(u > 0) u -= factor;
            if(aH > h) break;
            aH -= d;
            if(aH < 0) break;
            day++;
        }
        if(aH > 0) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day); 
    }
    return 0;
}