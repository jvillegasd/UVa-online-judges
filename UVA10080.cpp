#include <bits/stdc++.h>

using namespace std;

double gx[150], gy[150], hx[150], hy[150];
bool graph[150][150], visited[150];
int match[150];

double dist(int i, int j){
    double x = gx[i] - hx[j];
    double y = gy[i] - hy[j];
    return sqrt(x*x + y*y);
}

bool DFS(int node, int m){
    for(int i = 0; i < m; i++){
        if(graph[node][i] && !visited[i]){
            visited[i] = true;
            if(match[i] < 0 || DFS(match[i], m)){
                match[i] = node;
                return true;
            }
        }
    }
    return false;
}

int fordFulkerson(int n, int m){
    int maxFlow = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        if(DFS(i, m)) maxFlow++;
    }
    return maxFlow;
}

int main(){
    int n, m, s, v;
    while(scanf("%d %d %d %d", &n, &m, &s, &v) == 4){
        for(int i = 0; i < n; i++) scanf("%lf %lf", &gx[i], &gy[i]);
        for(int i = 0; i < m; i++) scanf("%lf %lf", &hx[i], &hy[i]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dist(i, j) <= s*v) graph[i][j] = true;
                else graph[i][j] = false;
            }
        }
        printf("%d\n", n - fordFulkerson(n, m));
    }
    return 0;
}
/*
    Este es un problema de MBM o Maximum bipartite Matching, use el ford fulkerson para resolverlo, ya que
    para los grafos bipartitos, el matching se reduce a un problema de maximo flujo. El ford fulkerson
    posee varios tipos de modificaciones como:
        -) los caminos de aumento no se guardan
        -) en vez del grafo residual, se usa un vector que confirma el match
        -) la comprobacion del camino de aumento se hace en cada nodo de uno de los grafos en vez de
            siempre hacerlo desde el nodo source
        -) se supone que cada nodo tiene una capacidad de 1, por eso se usa un vector que confirma el match
        -) cuando se analiza si el nodo "u" puede hacer matching con el nodo "v", se tiene en cuenta si el
            nodo "x" que ya hizo matching con "v" puede hacerlo con otro con tal de que "u" pueda hacer
            matching con "v"
    Siguiendo con el problema, arme el grafo con los Gopher que si podrian llegar a los hoyos (para ahorrar espacio),
    luego, realize el ford fulkerson para obtener de los que si puderon salvarse, ya despues, solo es hacer complemento
*/