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
int MAXN = 1000001, spf[1000001];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void smallPF(){ //O(nlog(n)*log(n))
    spf[1] = 1;
    for(int i = 2; i < MAXN; i++) spf[i] = i;
    for(int i = 4; i < MAXN; i+=2) spf[i] = 2;
    for(int i = 3; i * i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i * i; j < MAXN; j+=i) if(spf[j] == j) spf[j] = i;
        }
    }
}

int fact(int num){ //O(log(n))
    int ans = 0;
    while(num != 1){
        ans++;
        num/=spf[num];
    }
    return ans;
}

int main(){
    smallPF();
    int n, ans[MAXN];
    ans[1] = 0;
    for(int i = 2; i < MAXN; i++) ans[i] = ans[i - 1] + fact(i);
    while(scanf("%d", &n) != EOF) printf("%d\n", ans[n]);
    return 0;
}