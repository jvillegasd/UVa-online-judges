#include <bits/stdc++.h>

using namespace std;

int main(){
    int step, mod, gen, seed=0;
    bool noChoice = false;
    while(scanf("%d %d", &step, &mod) == 2){
        vector<bool> visited(mod);
        seed = 0;
        noChoice = false;
        for(int i = 0; i < mod; i++){
            gen = (seed + step) % mod;
            if(visited[gen]){
                noChoice = true;
                break;
            }
            visited[gen] = true;
            seed = gen;
        }
        if(noChoice) printf("%10d%10d    Bad Choice\n\n", step, mod);
        else printf("%10d%10d    Good Choice\n\n", step, mod);
    }
    return 0;
}