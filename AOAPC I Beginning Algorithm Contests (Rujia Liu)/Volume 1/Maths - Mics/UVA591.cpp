#include <iostream>

using namespace std;

int main(){
    int N, K, height, bricks, min, max, minI, maxI, stacks[50], testCase = 0;
    while(true){
        cin >> N;
        if(testCase != 0) printf("\n");
        if(N == 0) break;
        K = 0;
        bricks = 0;
        for(int i = 0; i < N; i++){
            cin >> stacks[i];
            bricks += stacks[i];
        }
        height = bricks/N;
        bool change = true;
        for(int i = 0; i < N && change; i++){
            min = 101;
            max = -101;
            change = false;
            for(int j = 0; j < N; j++){
                if(stacks[j] < min && stacks[j] != height){
                    min = stacks[j];
                    minI = j;
                    change = true;
                }
            }
            for(int j = 0; j < N; j++){
                if(stacks[j] > max && stacks[j] != height){
                    max = stacks[j];
                    maxI = j;
                    change = true;
                }
            }
            if(change){
                int delta;
                if(max - height <= height - min){
                    delta = max - height;      
                }else delta = height - min;
                stacks[maxI] -= delta;
                stacks[minI] += delta;
                K += delta;
            }
        }
        testCase++;
        printf("Set #%d\n", testCase);
        printf("The minimum number of moves is %d.\n", K);
    }
    return 0;
}