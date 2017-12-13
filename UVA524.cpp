#include <stdio.h>

using namespace std;

int primeN[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}, ans[18] = {1}, n;

bool isPrime(int number){
    for(int i = 0; i < 13; i++) if(number == primeN[i]) return true;
    return false;
}

void DFS(int actual, bool visited[18]){
    if(actual == n){
        if(isPrime(ans[n - 1] + 1)){
            printf("1");
            for(int i = 1; i < n; i++) printf(" %d", ans[i]);
            printf("\n");
        }
        return;
    }else{
        for(int i = 2; i <= n; i++){
            if(visited[i]) continue;
            if(isPrime(i + ans[actual - 1])){
                visited[i] = true;
                ans[actual] = i;
                DFS(actual + 1, visited);
                visited[i] = false;
            }
        }
    }
}

int main(){
    int cases = 0;
    bool nl = false;
    while(scanf("%d", &n) == 1){
        cases++;
        if(nl) printf("\n");
        printf("Case %d:\n", cases);
        nl = true;
        bool visited[18] = {0};
        DFS(1, visited);
    }
    return 0;
}
/*
    La estrategia es tratar el circulo como un grafo y cada numero como un nodo, de esta manera se usaria el DFS para
    poder dar con la solucion, cuando la recursividad llegue al caso base se imprime el vector de respuesta, la 
    recursividad hace todo el trabajo, pero para que pueda imprimir en orden anti horario, se tiene que cambiar el 
    estado de visitado a falso luego del llamado recursivo, esto es para que se pueda volver a reutilizar el nodo. En
    otras palabras, no hay que dejarse confundir con que hay que imprimir ya sea en orden horario o no, realmente se 
    imprime todas las posibilidades.
*/