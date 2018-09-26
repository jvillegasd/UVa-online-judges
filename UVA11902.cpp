#include <bits/stdc++.h>

using namespace std;

bool visited[110], dom[110][110];
int adjM[110][110], n;

void DFS(int u){
    visited[u] = true;
    for(int i = 0; i < n; i++){
        if(adjM[u][i] == 1 && !visited[i]) DFS(i);
    }
}

int main(){
    int colT, rowT, tc, cont = 0;
    scanf("%d", &tc);
    while(cont < tc){
        printf("Case %d:\n", ++cont);
        memset(visited, false, sizeof(visited));
        memset(dom, false, sizeof(dom));
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) scanf("%d", &adjM[i][j]);
        }
        dom[0][0] = true;
        for(int i = 1; i < n; i++){ //Simular que el nodo i no existe para ver que nodos no son accesibles (Caso main)
            dom[0][i] = true;
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            DFS(0);
            for(int j = 0; j < n; j++) if(!visited[j]) dom[i][j] = true;
            dom[i][i] = true;
        }
        memset(visited, false, sizeof(visited));
        DFS(0); //Obtener que nodos son accesibles desde el nodo cero (Caso secundario)
        for(int i = 0; i < n; i++){
            printf("+");
            for(int k = 0; k < 2*n-1; k++) printf("-");
            printf("+\n");
            for(int j = 0; j < n; j++){
                if(dom[i][j] && visited[j]) printf("|Y");
                else printf("|N");
            }
            printf("|\n");
        }
        printf("+");
        for(int k = 0; k < 2*n-1; k++) printf("-");
        printf("+\n");
    }   
    return 0;
}
/*
    Como son casos pequeños, la estrategia es simular que un nodo i se remueve del grafo y tirar DFS, revisar que nodos
    no fueron accesibles si se quita el nodo i, entonces, el nodo i vendria siendo el dominador de los que no fueron 
    accesibles
*/