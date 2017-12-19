#include <stdio.h>

using namespace std;

int main(){
    long long int n;
    while(scanf("%lld", &n) && n >= 0){
        if(n != 1) printf("%lld%%\n", 100 * n / 4);
        else printf("0%%\n");
    }
    return 0;
}
/*
    Al cortar la esfera se nos genera una semiesfera, nos piden que calculemos la ganancia por area superficial, 
    asi que no consideraremos la semiesfera, sino, los dos semicirculos, dicho esto se divide el area del circulo 
    con la de la  esfera inicial: pi*r^2/4*pi*r^2 = 1/4 = 25%, es decir, por cada parte se va generando una 
    ganacia del 25%, digo esto debido a que la parte base es el area de la esfera, de aqui se puede generar una 
    funcion de coste: C(x) = 4*pi*r^2 + (x-1)*(4*pi*0.25*r^2).
*/