#include <stdio.h>
#include <cmath>
#include <string.h>


using namespace std;

int main(){
    int squares[50010][4] = {0}, n, number;
    memset(squares, 0, sizeof(squares)); //Para no usar 3 for-loop para inicializarlo
    for(int i = 0; pow(i, 2) <= 50000; i++){
        for(int j = 0; pow(j, 2) <= 50000; j++){
            for(int k = 0; pow(k, 2) <= 50000; k++){
                int tentativeAns = pow(i, 2) + pow(j, 2) + pow(k, 2);
                if(tentativeAns > 50000) break;
                if(squares[tentativeAns][3] != 0) continue;
                squares[tentativeAns][0] = i;
                squares[tentativeAns][1] = j;
                squares[tentativeAns][2] = k;
                squares[tentativeAns][3] = 1;
            }
        }
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d", &number);
        if(squares[number][3]) printf("%d %d %d\n", squares[number][0], squares[number][1], squares[number][2]);
        else printf("-1\n");
    }
    return 0;
}
/*
    La estrategia a usar es "memorizar" las raices, es decir, generar todas las soluciones antes de empezar, eso nos
    asegura un algoritmo optimizado en tiempo de ejecucion. Respecto a como se soluciono el problema, fui buscando con
    fuerza bruta todas las combinaciones donde una triada me de un numero que no se pase del 50000 (limite estipulado),
    en una matriz voy guardando en cada posicion cada numero de la triada hallada.
*/