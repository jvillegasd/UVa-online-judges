#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n!=0){
        if(n%2==0 && 3<=n-1){
            printf("%d\n", 3*n/2);
            for(int i = 1; i < n; i++) printf("%d %d\n", i, i+1);
            printf("%d %d\n", n, 1);
            for(int i = 1; i <= n/2; i++) printf("%d %d\n", i, n/2+i);
        }else printf("Impossible\n");
    }
    return 0;
}
/*
    Primero que nada, un grafo r-regular existe si y solo si 0<=r<=n-1 donde r y n no deben los dos impar,
    recordemos que un grafo existe si y solo si hay un numero par de vertices de grado impar o si estos dos numeros 
    son par. Para generar el grafo encontre un patron que era que si primero unos los i-esimos nodos con los i+1-esimos, 
    y al final el n-esimo con el primer nodo, me gastaria n aristas y todos los nodos tendrian grad(G) = 2, entonces, 
    uno la primera mitad de los nodos con la segunda mitad.
*/