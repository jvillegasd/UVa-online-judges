#include <stdio.h>

using namespace std;

int main(){
    int n, m, cases;
    scanf("%d", &cases);
    while(cases-- > 0){
        scanf("%d %d", &n, &m);
        printf("%d\n", (n/3)*(m/3));
    }
    return 0;
}
/*
    La estrategia es usar algo de algebra lineal (matrices particionadas), cada sonar maneja un rango de una matriz 3x3, 
    por lo tanto, lo que nos pide es cuantas matrices particionadas de 3x3 contiene la matriz que representa el rio, 
    eso se obtiene dividiendo el numero de columnas entre 3, el numero de filas entre 3 y luego multiplicarlos.
*/