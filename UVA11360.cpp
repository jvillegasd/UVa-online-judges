#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int matriz[11][11];

void increase(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] += 1;
            if(matriz[i][j] == 10) matriz[i][j] = 0;
        }
    }
}

void decrease(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] -= 1;
            if(matriz[i][j] == -1) matriz[i][j] = 9;
        }
    }
}

void changeRow(int a, int b, int n){
    for(int i = 0; i < n; i++) swap(matriz[a][i], matriz[b][i]);
}

void changeCol(int a, int b, int n){
    for(int i = 0; i < n; i++) swap(matriz[i][a], matriz[i][b]);
}

void transpose(int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++) swap(matriz[i][j], matriz[j][i]);
    }
}

int main(){
    int tc, n, op, cont = 0;
    string opS;
    cin >> tc;
    while(cont < tc){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) scanf("%1d", &matriz[i][j]); //Para tomar un solo numero
        }
        cin >> op;
        while(op-- > 0){
            cin >> opS;
            if(opS == "inc") increase(n);
            else if(opS == "dec") decrease(n);
            else if(opS == "transpose") transpose(n);
            else if(opS == "row"){
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                changeRow(a, b, n);
            }else if(opS == "col"){
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                changeCol(a, b, n);
            } 
        }
        printf("Case #%d\n", cont + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) printf("%d", matriz[i][j]);
            printf("\n");
        }
        printf("\n");
        cont++;
    }
    return 0;
}