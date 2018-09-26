#include <bits/stdc++.h>

using namespace std;

vector<int> graph[150000];
stack<int> scc;
int inDegree[150000];
bool visited[150000];

void SCC_DFS(int u){
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]) SCC_DFS(v);
    }
    scc.push(u);
}

void DFS(int u){
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]) DFS(v);
    }
}

int main(){
    int tc, n, m, u, v, knock = 0;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++) graph[i].clear();
        knock = 0;
        memset(visited, false, sizeof(visited));
        memset(inDegree, 0, sizeof(inDegree));
        for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), graph[u].push_back(v), inDegree[v]++;
        for(int i = 1; i <= n; i++) if(!visited[i]) SCC_DFS(i);
        memset(visited, false, sizeof(visited));
        while(!scc.empty()){
            int u = scc.top();
            scc.pop();
            if(!visited[u]){
                DFS(u);
                knock++;
            }
        }
        printf("%d\n", knock);
    }
    return 0;
}
/*
    Problema algo raro al inicio, la primera estrategia fue usar ordenamiento topologico para obtener con que nodo
    empezar para simular la situacion, pero, no cai en cuenta que salia mas sencillo al hallar las componentes
    fuertemente conexas y contarlas.
*/