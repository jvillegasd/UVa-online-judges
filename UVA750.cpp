#include <stdio.h>

using namespace std;

int sol;

void backtracking(int currentCol, int colI, int col[15], bool row[15], bool dig1[20], bool dig2[20]){
    if(currentCol == colI){
        backtracking(currentCol + 1, colI, col, row, dig1, dig2);
    }else if(currentCol == 9){
        sol++;
        printf( "%2d     ", sol);
        for(int i = 1 ; i <= 8 ; i++ ) printf( " %d", col[i]);
        printf( "\n" );
    }else{
        for(int i = 1; i <= 8; i++){
            if(!row[i] && !dig1[currentCol + i] && !dig2[i - currentCol + 8]){
                row[i] = dig1[currentCol + i] = dig2[i - currentCol + 8] = true;
                col[currentCol] = i;
                backtracking(currentCol + 1, colI, col, row, dig1, dig2);
                row[i] = dig1[currentCol + i] = dig2[i - currentCol + 8] = false;
                col[currentCol] = 0;
            }
        }
    }
}

int main(){
    int dataset, colI, rowI;
    scanf("%d", &dataset);
    for(int i = 0; i < dataset; i++){
        if(i > 0) printf("\n");
        scanf("%d %d", &rowI, &colI);
        int col[15] = {0};
        bool row[15] = {0}, dig1[20] = {0}, dig2[20] = {0};
        col[colI] = rowI;
        row[rowI] = true;
        dig1[colI + rowI] = true;
        dig2[rowI - colI + 8] = true;
        printf( "SOLN       COLUMN\n");
        printf( " #      1 2 3 4 5 6 7 8\n\n" );
        sol = 0;
        backtracking(1, colI, col, row, dig1, dig2);
    }
    return 0;
}
/*
    La estrategia es algo parecida a la usada en el UVA524, usar backtracking/DFS para poder buscar todas las soluciones
    posibles, aqui cambia algunas cosas, para facilitar la busqueda en vez de usar una matriz use dos vector, el de 
    las columnas guardo todas las filas que pertenecen a la solucion (para mostrar la respuesta) y el 
    vector de las filas es booleano para indicar que hay una reina ubicada, tambien use dos vectores mas para las 
    diagonales, en este uso dos formulas para saber la diagonal que le pertenece a una fila, estas son: 
    dig1 = col + row, y dig2 = row - col + 8.
*/