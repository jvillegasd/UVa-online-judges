#include <bits/stdc++.h>

using namespace std;

int parent[200];

float getDist(pair<int, int> p1, pair<int, int> p2){
    float x = p1.first - p2.first, y = p1.second - p2.second;
    return sqrt(x*x + y*y);
}

int cmp(const pair<float, pair<int, int> >& p1, const pair<float, pair<int, int> >& p2){
    return p1.first < p2.first;
}

void makeSet(int n){
    for(int i = 0; i < n; i++) parent[i] = i;
}

int find(int i){
    if(i == parent[i]) return i;
    return find(parent[i]);
}

bool sameSet(int i, int j){
    return find(i) == find(j);
}

void unionSet(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    parent[iRoot] = jRoot;
}

int main(){
    int n, tc;
    float x, y;
    vector<pair<float, float> > points;
    vector<pair<float, pair<int, int> > > edges;
    vector<pair<float, pair<int, int> > > kruskal;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        points.clear();
        edges.clear();
        kruskal.clear();
        makeSet(n);
        for(int i = 0; i < n; i++) scanf("%f %f", &x, &y), points.push_back(make_pair(x, y));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                float w = getDist(points[i], points[j]);
                pair<int, int> nodes = make_pair(i, j);
                edges.push_back(make_pair(w, nodes));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        for(int i = 0; i < edges.size(); i++){
            int nodeI = edges[i].second.first, nodeJ = edges[i].second.second;
            if(!sameSet(nodeI, nodeJ)){
                kruskal.push_back(edges[i]);
                unionSet(nodeI, nodeJ);
            }
        }
        float total = 0;
        for(int i = 0; i < kruskal.size(); i++) total+=kruskal[i].first;
        printf("%.2f\n", total);
        if(tc) printf("\n");
    }
    return 0;
}
/*
    Problema sencillo, la estrategia es encontrar el MST y sumar los pesos de este para obtener la respuesta.
    Para hallar el MST hay que armar el grafo, osea, cada coordenada son nodos y el grafo lo sacas uniendo cada
    puntos con todos, es decir, obtener un grafo Kn. Luego, a ese grafo le sacas el MST, yo use Kruskal por
    cuestiones de practica.
*/