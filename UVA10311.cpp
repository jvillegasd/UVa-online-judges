#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];
bool primes[100000000];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void sieve(){
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;
    for(lli i = 2; i*i <= 100000000; i++){
        if(primes[i]) for(lli j = i*i; j <= 100000000; j+=i) primes[j] = 0;
    }
}

int main(){
    int flag;
    lli n;
    sieve();
    while(scanf("%lld", &n) != EOF){
        if(n&1){
            if(primes[n - 2]) printf("%lld is the sum of 2 and %lld.\n", n, n - 2);
            else printf("%lld is not the sum of two primes!\n", n);
        }else{
            flag = 1;
            for(lli i = (n/2) - 1; i >= 2; i--){
                if(primes[i] && primes[n - i]){
                    printf("%lld is the sum of %lld and %lld.\n", n, i, n - i);
                    flag = 0;
                    break;
                }
            }
            if(flag) printf("%lld is not the sum of two primes!\n", n);
        }
    }
    return 0;
}
/*
    Ignorar casos: 1 + 1 = 2, 1 + 2 = 3.
*/