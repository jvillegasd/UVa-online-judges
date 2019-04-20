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
bool prime[20000000];
int twin[1000000];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void sieve(){
    int j = 1;
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for(int i = 2; i*i <= 20000000; i++){
        if(prime[i]) for(int j = i*i; j <= 20000000; j+=i) prime[j] = 0;
    }
    for(int i = 3; i <= 20000000; i++) if(prime[i] && prime[i + 2]) twin[j++] = i;
}

int main(){
    int n;
    sieve();
    while(scanf("%d", &n) != EOF) printf("(%d, %d)\n", twin[n], twin[n] + 2);
    return 0;
}