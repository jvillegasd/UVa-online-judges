#include <iostream>
#include <cstring>

using namespace std;            //No usar matrices para optimizar tiempos

int main(){
    int DNA[10];
    int n, cont = 0;
    cin >> n;
    while(cont < n){
        int today[43] = {0};
        int aux[43] = {0};
        today[20] = 1;                           
        for(int i = 0; i < 10; i++) cin >> DNA[i];
        for(int i = 0; i < 50; i++){
            for(int j = 1; j <= 40; j++){           //Por comodidad
                if(today[j] == 1) cout << ".";
                else if(today[j] == 0) cout << " ";
                else if(today[j] == 2) cout << "x";
                else cout << "W";
            }
            cout << endl;
            memcpy(aux, today, sizeof(aux));
            int jLeft, jRight, dish;
            for(int j = 1; j <= 40; j++){
                jLeft = j - 1; 
                if(j == 40) jRight = 0;
                else jRight = j + 1;
                dish = aux[jLeft] + aux[j] + aux[jRight];
                today[j] = DNA[dish];
            }
        }
        if(cont != n - 1) cout << endl;
        cont++;
    }
    return 0;
}