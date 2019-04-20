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
int primes[33000];
vector<int> p;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void sieve(){
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;
    for(int i = 2; i*i <= 33000; i++){
        if(primes[i]) for(int j = i*i; j <= 33000; j+=i) primes[j] = 0;
    }
    for(int i = 2; i <= 33000; i++) if(primes[i]) p.pb(i);
}

int main(){
    sieve();
    int x, y, low, i, j, delta;
    while(scanf("%d %d", &x, &y)){
        if(!x && !y) break;
        if(x > y) swap(x, y);
        low = 0;
        while(p[low] < x) low++;
        while(p[low + 2] <= y){
            if(p[low + 2] - p[low + 1] == p[low + 1] - p[low]){
                i = low;
                j = low + 2;
                delta = p[low + 1] - p[low];
                while(low + 3 < p.size() && p[low + 3] - p[low + 2] == delta){
                    j++;
                    low++;
                }
                if(p[j] <= y){
                    if(!i || p[i] - p[i - 1] != delta){
                        printf("%d", p[i]);
                        for(int k = i + 1; k <= j; k++) printf(" %d", p[k]);
                        printf("\n");
                    }
                } else break;
            }
            low++;
        }
    }
    return 0;
}
/*
    Brute force para hallar los primos uni-distantes.
*/