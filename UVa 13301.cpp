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
vector<int> g[100000], invG[100000];
bool vist[100000];
stack<int> s;
int cnt, n;

void DFS1(int u){
    vist[u] = true;
    for(auto v : g[u]) if(!vist[v]) DFS1(v);
    s.push(u);
}

void DFS2(int u){
    vist[u] = true;
    for(auto v : invG[u]) if(!vist[v]) DFS2(v);
}

void SCC(){
    cnt = 0;
    memset(vist, false, sizeof(vist));
    for(int u = 1; u <= n; u++) if(!vist[u]) DFS1(u); //Realizar DFS con el grafo para obtener nodos con el mayor tiempo de llegada
    memset(vist, false, sizeof(vist));
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!vist[v]){ //Imprimir SCC
            DFS2(v);
            cnt++;
        }
    }
}

int main(){
    int m, u, v, k;
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++) g[i].clear(), invG[i].clear();
        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &k, &u, &v);
            if(k == 1){
                dEdge(u, v);
                invG[v].pb(u);
            }else{
                uEdge(u, v);
                invG[u].pb(v);
                invG[v].pb(u);
                for(int i = 2; i < k; i++){
                    scanf("%d", &u);
                    uEdge(v, u), invG[u].pb(v), invG[v].pb(u), v = u;
                }
            }
        }
        SCC();
        if(cnt == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}