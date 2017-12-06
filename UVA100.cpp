#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int i, j, auxI, auxJ, max, cycle;
    while(cin >> i >> j){
        auxI = i;
        auxJ = j;
        if(i > j) swap(i, j);
        max = -1;
        while(i <= j){
            cycle = 1;
            long long int n = i;
            while(n != 1){
                if(n % 2 == 1) n = 3 * n + 1;
                else n /= 2;
                cycle++;
            }
            if(cycle > max) max = cycle;
            i++;
        }
        printf("%d %d %d\n", auxI, auxJ, max);
    }
    return 0;
}