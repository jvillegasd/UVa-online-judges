#include <iostream>

using namespace std;

int main(){
    int N, x, y, delta, minStep, len;
    bool changeLen;
    cin >> N;
    while(N-- > 0){
        cin >> x >> y;
        delta = y - x;
        minStep = 0;
        len = 1;
        changeLen = false;
        while(delta > 0){
            delta -= len;
            minStep++;
            if(changeLen) len++;
            changeLen = !changeLen;
        }
        printf("%d\n", minStep);
    }
    return 0;
}
// Ir aumentando el tam de los pasos en 1, pero cada dos pasos, asi como en la vida real