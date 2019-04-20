#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    string highway;
    int l;
    while(scanf("%d", &l) && l != 0){
        cin >> highway;
        int minDistance = l, lastR = -1, lastD = -1;
        bool zFound = false;
        for(int i = 0; i < l; i++){
            if(highway[i] == 'Z'){
                printf("0\n");
                zFound = true;
                break;
            }
            if(highway[i] == 'R') lastR = i;
            if(highway[i] == 'D') lastD = i;
            if(lastR >= 0 && lastD >= 0) minDistance = min(minDistance, abs(lastD - lastR));
        }
        if(!zFound) printf("%d\n", minDistance);
    }
    return 0;
}