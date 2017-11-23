#include <iostream>

using namespace std;

int main(){
    int n, amplitude, frecuency, auxIndex, cont = 0;
    cin >> n;
    while(cont < n){
        cin >> amplitude >> frecuency;
        for(int k = 0; k < frecuency; k++){
            auxIndex = 0;
            if(k > 0 || cont > 0) cout << endl;
            for(int i = 1; i < 2*amplitude; i++){
              if(i > amplitude) auxIndex +=2;
              for(int j = 1; j <= i - auxIndex; j++) cout << i - auxIndex;
              cout << endl;
            }
        }
        cont++;
    }
    return 0;
}