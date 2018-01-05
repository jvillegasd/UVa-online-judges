#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    unsigned long long s2[101], s3[101], s4[101], r2[101], r3[101], r4[101], n;
    s2[0] = s3[0] = s4[0] = r2[0] = r3[0] = r4[0] = 0;
    for(int i = 1; i <= 100; i++){
        s2[i] = s2[i - 1] + pow(i, 2);
        s3[i] = s3[i - 1] + pow(i, 3);
        s4[i] = s4[i - 1] + pow(i, 4);
        r2[i] = pow(i * (i + 1) / 2, 2) - s2[i];
        r3[i] = pow(i * (i + 1) / 2, 3) - s3[i];
        r4[i] = pow(i * (i + 1) / 2, 4) - s4[i];
    }
    while(scanf("%d", &n) == 1) printf("%llu %llu %llu %llu %llu %llu\n", s2[n],r2[n],s3[n],r3[n],s4[n],r4[n]);
    return 0;
}
/*
    -) Para hallar el patron de las figuras de igual dimension (cuadrados):
        Ejemplo usado: En un cuadrado 1x1 solo tenemos un cuadrado, al aumentar a 2x2 obtendriamos 5 que puede ser 
        hallado multiplicando 2x2 y teniendo en cuenta el cuadrado grande, pero vendria siendo lo mismo que sumar el
        cuadrado 1x1 anterior, ahora tengamos en cuenta uno 3x3, aqui seria 14 cuadrados que son 3x3 + 2x2 + 1x1
        que seria igual 9(lenght 1) + 4(lenght 2) + 1(lenght 3) y he aqui el patron y es que 2x2 + 1x1 viene 
        siendo los cuadrado 2x2, entonces la formula seria C[i] = C[i - 1] + pow(i, 2), para las demas dimensiones
        es lo mismo por lo que llevaria a la formula general C[i] = C[i - 1] + pow(i, dimesion).

    -) Para hallar el patron de las figuras de diferente dimesion (rectangulos, GeeksforGeeks):
        Ejemplo usado: En una cuadricula 1x1 hay 1 rectangulo de 1x1 (cuadrado), bien, si ahora usamos una de 2x1 
        habrian 2 rectangulos 1x1(cuadrados) y uno 2x1 que es igual a 2 + 1 = 3, ahora si colocamos uno 3x1 seria 
        3 + 2 + 1 = 6, vemos que se comporta como numeros triangulares para Nx1, entonces para cualquier dimension 
        seria: R[i] = pow(i * (i + 1) / 2, dimension) - C[i] (debido a que cuenta tambien los cuadrados).
*/