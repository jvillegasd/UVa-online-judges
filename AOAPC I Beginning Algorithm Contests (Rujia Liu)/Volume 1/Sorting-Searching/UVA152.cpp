#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int main(){
    int trees[5001][3];
    int ans[10];
    int val = 0, minD;
    while(true){
        cin >> trees[val][0] >> trees[val][1] >> trees[val][2];
        if(trees[val][0] == 0 && trees[val][1] == 0 && trees[val][2] == 0) break;
        val++;
    }
    for(int i = 0; i < val; i++){
        minD = numeric_limits<int>::max();
        for(int j = 0; j < val; j++){
            if(i == j) continue;
            int dx = trees[i][0] - trees[j][0];
            int dy = trees[i][1] - trees[j][1];
            int dz = trees[i][2] - trees[j][2];
            int distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
            if(distance < minD) minD = distance;
        }
        if(minD <= 9) ans[minD]+=1;
    }
    for(int i = 0; i < 10; i++) printf("%4d", ans[i]);
    printf("\n");
    return 0 ;
}