#include <iostream>
#include <algorithm>

using namespace std;   //Programacion dinamica

int main(){
    int m, n, t, DP[10000];
      while(true){
        cin >> m >> n >> t;
        if(cin.fail()) break;
        DP[0] = 0;
        for(int i = 1; i <= t; i++){
          DP[i] = -1;
          if(m <= i && DP[i - m] != -1) DP[i] = DP[i - m] + 1; //Calcular con una hamburguesa
          if(n <= i && DP[i - n] != -1) DP[i] = max(DP[i - n] + 1, DP[i]); //Calcular con la otra y ver cual es el mayor
        }
        if(DP[t] != -1) cout << DP[t] << endl; //Significa que ocupó todo el tiempo comiendo
        else{
            for(int i = t; i >= 0; i--){ //Significa que le sobró tiempo, entonces hay que buscar el tiempo maximo
              if(DP[i] != -1){
                  cout << DP[i] << " " << t - i << endl;
                  break;
              }
            }
          }
        }
  return 0;
}