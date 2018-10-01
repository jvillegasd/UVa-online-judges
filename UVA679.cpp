#include <bits/stdc++.h>

using namespace std;

int d, l, maxN;

int drop(int node, int balls){
    int left = 2 * node, right = 2 * node + 1;
    if(left < maxN && right < maxN){
        if(balls % 2 == 0) return drop(right, balls / 2);
        else return drop(left, balls/2 + 1);
    }
    else return node;
}

int main(){
    int tc, stop;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &d, &l);
        maxN = pow(2, d);
        printf("%d\n", drop(1, l));
    }
    return 0;
}
/*
    Problema muy estresante, spoilers: simulacion te da TLE. La estrategia es usar Binary Search para poder sacar
    la respuesta, si nos ponemos a pensar, el numero de pelotas nos dice si el nodo permanece verdadero (par) o
    falso (impar), ademas, que cada vez que se mueve una pelota, una mitad de las demas sigue el camino y la otra 
    se va por el lado contrario.
*/