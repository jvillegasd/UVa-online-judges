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

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

int main(){
    int n, m, k, v, ni;
    vector<vector<int>> arr;
    while(scanf("%d %d", &n, &m) != EOF){
        arr.assign(1000000, vector<int>());
        for(int i = 1; i <= n; i++) scanf("%d", &ni), arr[ni].pb(i);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &k, &v);
            if(k - 1 < arr[v].size()) printf("%d\n", arr[v][k - 1]);
            else printf("0\n");
        }
    }
    return 0;
}