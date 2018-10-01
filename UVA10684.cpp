#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n != 0){
        int input[n + 1], sum = 0, sumA = 0;
        for(int i = 0; i < n; i++) scanf("%d", &input[i]);
        for(int i = 0; i < n; i++){
            sumA += input[i];
			if (sumA > sum) sum = sumA;
			if (sumA < 0) sumA = 0;
        }
        if(sum > 0) printf("The maximum winning streak is %d.\n", sum);
        else printf("Losing streak.\n");
    }
    return 0;
}