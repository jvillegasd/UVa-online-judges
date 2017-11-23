#include <iostream>

using namespace std;

int main(){
    long A, L, cont, cCase = 1, aux;
    while(true){
        cin >> A >> L;
        aux = A;
        if(A < 0 && L < 0) break;
        cont = 0;
        while(aux != 1 && aux <= L){
            cont++;
            if(aux % 2 == 0) aux /= 2;
            else aux = 3 * aux + 1;
            if(aux == 1) cont++;
        }
        cout<<"Case "<<cCase<<": "<<"A = "<<A<<", limit = "<<L<<", number of terms = "<<cont<<endl;
        cCase++;
    }
    return 0;
}