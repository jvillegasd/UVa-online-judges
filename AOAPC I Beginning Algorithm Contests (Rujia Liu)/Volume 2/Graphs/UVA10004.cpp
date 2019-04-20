#include <iostream>
#include <stack>
#include <vector>

using namespace std;                      //Bicolorable graph == bipartite graph

int matrizA[200][200] = { }, colores[200] = { };

bool DFS(int n){
    vector<bool> visitado(n, false);
    bool bicoloreable = true;
    stack<int> pila;
    pila.push(0);
    colores[0] = 0;
    while(!pila.empty() && bicoloreable){
        int vertice = pila.top();
        pila.pop();
        visitado[vertice] = true;
        for(int i = 0; i < n; i++){
            if(matrizA[i][vertice] == 1 && !visitado[i]){
                visitado[i] = true;
                colores[i] = 1 - colores[vertice];
                pila.push(i);
            }else if(matrizA[i][vertice] == 1 && colores[i] == colores[vertice] && i != vertice){
                bicoloreable = false;
                break;
            }
        }
    }
    visitado.clear();
    return bicoloreable;
}

void reset(){
    for(int i = 0; i < 200; i++){
        colores[i] = 0;
        for(int j = 0; j < 200; j++){
            matrizA[i][j] = 0;
        }
    }
}

int main(){
    int n, l, vertice1, vertice2;
    while(true) {
        cin >> n;
        if(n == 0) break;
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> vertice1 >> vertice2;
            matrizA[vertice1][vertice2] = 1;
            matrizA[vertice2][vertice1] = 1;
        }
        if(DFS(n)) cout << "BICOLORABLE." << endl; else cout << "NOT BICOLORABLE."<<endl;
        reset();
    }
    return 0;
}