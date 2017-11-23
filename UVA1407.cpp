#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;     //Programacion dinamica

int main(){
    int DP[10007], t, N;
    for(int i = 0; i <= 10000; i++) DP[i] = i; //Inicializar DP[] con los valores de sus indices
    for(int i = 1; i <= 10000; i++){ //Buscar los numeros que elevados al cuadrado y se sumen den el numero deseado 
        for(int j = 1; j <= sqrt(i); j++){ //Por eso el limite que deben tener es la raiz de numero deseado
            DP[i] = min(DP[i], DP[i - j*j] + 1); //Hallando la cantidad minima de los numeros a sumar
        }
    }
    cin >> N;
    while(N-- > 0){
        cin >> t;
        cout << DP[t] << endl;
    }
    return 0;
}