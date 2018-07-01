#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

int main(){
    int tc, n;
    string desired;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        getchar();
        vector<string> turtles(n);
        map<string, int> desMap;
        for(int i = 0; i < n; i++) getline(cin, turtles[i]);
        for(int i = 0; i < n; i++){
            getline(cin, desired);
            desMap[desired] = i;
        }
        vector<pair<string, int>> ans;
        for(int i = n-1, j = n-1; i >= 0; i--){
            if(desMap[turtles[i]] != j) ans.push_back(make_pair(turtles[i], desMap[turtles[i]]));
            else j--;
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); i++) cout<<ans[i].first<<endl;
        printf("\n");
    }
    return 0;
}
/*
    La manera de realizar los intercambios es ver los nombres de las tortugas cuya posicion no sea consecutiva, se explica
    mejor con el siguiente ejemplo: Imagina que en un caso de prueba al enumerar el orden de las torturas que te dieron
    de la primera lista queda asi: 1 4 3 5 6 2, aqui los numeros consecutivos son: 4, 5 y 6, por lo que tendriamos que
    mover solamente el 1,2 y 3. Ojo: Debe resolverse mirando la lista de atras para adelante debido a que el problema
    usa una pila, es decir, moverse hacia arriba es el unico movimiento posible, ademas, cada movimiento si o si lleva
    a la tortuga al top (posicion 1)
*/