#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int manhattan[1025][1025], n, d, x, y, nest, tam, maxTam;
    scanf("%d", &n);
    while(n--){
        memset(manhattan, 0, sizeof(manhattan));
        scanf("%d %d", &d, &nest);
        for(int i = 0; i < nest; i++){
            scanf("%d %d %d", &x, &y, &tam);
            for(int j = max(0, y - d); j <= y + d && j < 1025; j++){
                for(int k = max(0, x - d); k <= x + d && k < 1025; k++) manhattan[j][k]+=tam;
            }
        }
        maxTam = 0;
        for(int i = 0; i < 1024; i++){
            for(int j = 0; j < 1024; j++){
                if(manhattan[j][i] > maxTam){
                    maxTam = manhattan[j][i];
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d %d\n", x, y, maxTam);
    }
    return 0;   
}
/*
    Si bien se podria buscar casilla a casilla e ir sumando para ver cual ubicacion mata mas ratas, pero eso es muy
    complejo y demoraria mucho, lo que hice fue que en cada ubicacion en donde colocaba el nido llenaba la matriz
    de ese numero alrededor de esa ubicacion dependiendo el rango de la bomba, eso para simular que la bomba fue
    puesta ahi, esto lo hago porque esos rangos se pueden intersectar con otros nidos, por lo que voy a buscar es
    la ubicacion donde mas se halla intersectado. PD: buscar de columna en columna, por alguna razon si lo buscas
    en fila en fila UVa manda WA.
*/