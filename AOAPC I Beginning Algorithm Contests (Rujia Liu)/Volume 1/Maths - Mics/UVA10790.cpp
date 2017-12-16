#include <stdio.h>

using namespace std;

int main(){
    int cont = 0, a , b;
    while(scanf("%d %d", &a, &b) && a != 0 && b!= 0){
        cont++;
        printf("Case %d: %lld\n", cont, (long long)a*b*(a-1)*(b-1)/4);
    }
    return 0;
}
/*
    Para entender la solucion hay que explicarlo con un ejemplo, imagina que en la linea de arriba tienes un punto 
    llamado A1 (ubicalo en el centro, cosa que este abajo de B2), en la linea de abajo tienes 4 puntos 
    llamados: B1, B2, B3, B4. Si los conectas te daras cuenta de que no se intersectan ninguna linea, bien, ahora 
    agrega un punto A2 a la linea de arriba y observa que en una linea intersecta 1 vez, con otra intersecta 2 veces y
    en la tercera intersecta 3 veces, si no lo viste, entonces agregar otro punto A3 a la linea de arriba y observa
    de nuevo, aqui obtendras una linea que intersecta 6 veces, otra con 4, otra con 2, entonces obtenemos esto: 
    Suma de las intersecciones:
    0
    3 + 2 + 1 = (3 + 2 + 1) * 1
    6 + 4 + 2 = (3 + 2 + 1) * 2
    son secuencias triangulares de manera vertical y horizontal!.
*/