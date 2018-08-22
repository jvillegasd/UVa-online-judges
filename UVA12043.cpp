#include <stdio.h>
#include <math.h>

using namespace std;

int d[100100], sigma[100100];

void divisors(){
    for(int i = 1; i <= 100000; i++){
        for(int j = i; j <= 100000; j+=i) d[j]++, sigma[j]+=i;
    }
}

int main(){
    int tc;
    long long int a, b, c, g, h;
    divisors();
    scanf("%d", &tc);
    while(tc--){
        scanf("%lld %lld  %lld", &a, &b, &c);
        g = h = 0;
        for(int i = a; i <= b; i++) if(i % c == 0) g+=d[i], h+=sigma[i];
        printf("%lld %lld\n", g, h);
    }
    return 0;
}