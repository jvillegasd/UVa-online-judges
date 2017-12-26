#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const int &i, const int &j){
    if(i > j) return true;
    return false;
}

int main(){
    int tc, n, m, time, priority, indexPP;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        queue<pair<int, int>> cola;
        vector<int> printPriority;
        for(int i = 0; i < n; i++){
            cin >> priority;
            cola.push(make_pair(priority, i));
            printPriority.push_back(priority);
        }
        time = 0;
        indexPP = 0;
        sort(printPriority.begin(), printPriority.end(), cmp);
        while(!cola.empty()){
            int prior = cola.front().first;
            int index = cola.front().second;
            cola.pop();
            if(prior == printPriority[indexPP]){
                time++;
                if(index == m) break;
                indexPP++;
            }else cola.push(make_pair(prior, index));
        }
        printf("%d\n", time);
    }
    return 0;
}
/*
    La estrategia es seguir al pie de la letra lo que te piden, para facilitarme el trabajo use un vector y una queue,
    el vector me tiene organizado las prioridades y con la queue pues simulo normalmente la queue, para la queue tuve
    que instancearla con pair para que a cada prioridad le guarde su indice, esto es para saber cuando tengo que parar.
    Llegue a esta solucion porque intente hacer este problema usando estas estructura de manera separada, primero
    como era problema de queue, entonces use una queue pero al razonar bien entendi que practicamente se podria
    resolver organizando el vector pero tenia que tener en cuenta donde quedaba en indice de "my job" y eso no lo
    pude controlar asi que lo hice de esta manera.
*/