#include <iostream>
#include <string.h>
#include <string>

using namespace std;

bool KMP(string input, int jump){
    for(int i = 0; i < jump; i++){
        char pattern = input[i];
        for(int j = i + jump; j < input.size(); j+=jump){
            if(input[j] != pattern) return false;
        }
    }
    return true;
}

int main(){
    int n;
    string input;
    cin >> n;
    while(n--){
        cin >> input;
        int i;
        for(i = 1; i < input.size(); i++){
            if(input.size() % i != 0) continue; //No puede ser un patron.
            if(KMP(input, i)){ //La substr de 0->i es un patron.
                printf("%d\n", i);
                break;
            }
        }
        if(i == input.size()) printf("%d\n", i);
        if(n) printf("\n");
    }
    return 0;
}
/*
    La estrategia a usar es KMP para buscar el patron, pero hay que modificarlo ya que no nos dan el patron,
    entonces lo que hago para simular ese patron es usar indices, pero los indices que sean multiplos del tamaño
    de la string ya que asi simulo que de lo que esta de ese indice hasta cero es mi patron a buscar. 
    Aprendizaje: Yo habia leido algo sobre KMP mucho antes de encontrarme con este problema pero no lo suficiente para
    entenderlo. Para realizar este ejercicio tuve que leer sobre KMP y sus principios.
    A tener en cuenta: El patron que se busca debe tener indice multiplo del tamaño de la string debido a que ese
    patron debe repetirse de manera uniforme en toda la string.
*/