#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        long long ans = 0;
        for (int i = 0; 2*i <= n; i++) ans+=i + 1;
        printf("%lld\n", ans);
    }
  return 0;
}
/*
    Un problema bastante sencillo si se observa el patron de la solucion. El truco aqui es implementar por fuerza bruta
    la solucion primero y observar si la solucion tiene un patron, efectivamente si lo tiene. El patron es la sumatoria 
    de los primeros n numeros pero con dos condiciones:
    1) El resultado se repite en parejas, donde un numero de la pareja es un n par y el n+1 es impar
    2) Tiene un desfase de 1
*/