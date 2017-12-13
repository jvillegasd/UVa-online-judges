#include <stdio.h>

using namespace std;

int main(){
    int n;
    bool nl = false;
    while(scanf("%d", &n) == 1 && n != 0){
        if(nl) printf("\n");
        nl = true;
        bool exists = false;
        for(int i = 1234; i <= 99999; i++){
            if(i * n > 99999) break;
            bool used[10], possible = true;
            for(int j = 0; j < 10; j++) used[j] = false;
            char number[10];
            sprintf(number, "%05d", i); //Genera una string con un formato a partir de un entero
            for(int j = 0; number[j]; j++) used[number[j] - '0'] = true;
            sprintf(number, "%05d", i * n);
            for(int j = 0; number[j]; j++) used[number[j] - '0'] = true;
            for(int j = 0; j < 10; j++){
                if(!used[j]){
                    possible = false;
                    break;
                }
            }
            if(possible){
                printf("%05d / %05d = %d\n", i * n, i, n);
                exists = true;
            }
        }
        if(!exists) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
/*
    La estrategia es ir hallando a fuerza bruta la solucion, una manera facil es hallar un numero y en un vector de
    booleanos marcar como verdadero los numeros usados, luego a ese numero se le multiplica por el numero de la input y
    se marcan en el mismo vector los numeros usados, si todo el vector esta en verdadero entonces esa es respuesta 
    (division entre 1), ya que el ejercicio pide que sean numeros diferentes, ademas, como el numero puede empezar 
    con cero por delante, se empieza por el 1234.
*/