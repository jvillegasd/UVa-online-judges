#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, arr[55], aux;
    while(scanf("%d", &n) && n != 0){
        aux = n;
        bool space = true;
        for(int i = 0; i < n; i++) arr[i] = aux, aux--;
        printf("Discarded cards:");
        while(n > 1){
            if(space) printf(" "), space = false;
            printf("%d", arr[n - 1]);
            if(n > 2) printf(", ");
            n--;
            for(int i = n - 1; i - 1 >= 0; i--) swap(arr[i], arr[i - 1]);
        }
        printf("\nRemaining card: %d\n", arr[0]);
    }
    return 0;
}