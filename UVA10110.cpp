#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n;
    while(scanf("%lld", &n) && n != 0){ 
        if((int)sqrt(n) == sqrt(n)) printf("yes\n");
        else printf("no\n");  
    }
    return 0;
}
/*
    La estratega a usar es un teorema de la teoria de numeros que dice: 
                "Si n tiene sqrt(n) perfecta, entonces, n posee un numero impar de factores".
*/