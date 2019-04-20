#include <iostream>
#include <string>

using namespace std;

string matriz[201][201];
string ganador;
const int direcciones[][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};

void DFS(int n, string letraO, int i, int j){
    matriz[i][j] = "";
    if(letraO == "w" && j == n - 1){
        ganador = "W";
    }else if(letraO == "b" && i == n - 1){
        ganador = "B";
    }
    for(int k = 0; k < 6; k++){
        int ni = i + direcciones[k][0];
        int nj = j + direcciones[k][1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
        if(matriz[ni][nj] == letraO){
            DFS(n, letraO, ni, nj);
        }
    }
}

int main(){
    int n, juego = 1;
    string cadena;
    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> cadena;
            for(int j = 0; j < n; j++){
                matriz[i][j] = cadena.substr(j,1);
            }
        }
        for(int i = 0; i < n; i++){
            if(matriz[i][0] == "w"){
              DFS(n, "w", i, 0);
            }
        }
        for(int j = 0; j < n; j++){
            if(matriz[0][j] == "b"){
              DFS(n, "b", 0, j);
            }
        }
        cout << juego << " " << ganador <<endl;
        juego++;
    }
    return 0;
}