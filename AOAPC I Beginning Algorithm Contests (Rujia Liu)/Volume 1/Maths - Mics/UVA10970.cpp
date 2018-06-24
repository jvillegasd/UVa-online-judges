#include <stdio.h>
#include <math.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    long long int m,n;
    while(scanf("%lld %lld", &m, &n) != EOF){
        printf("%d\n", m*n-1);
    }
    return 0;
}