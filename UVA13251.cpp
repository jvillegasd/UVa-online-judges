#include <bits/stdc++.h> //Para aprenderme la liberia

using namespace std;

char input[200000];
set<string> term; //Para aprender a usarlo

void DFS(int index, int end){
  term.insert(input + index);
  int indexSub = -1;
  for(int i = index; i <= end; i++){
    if(!isalpha(input[i])){
      indexSub = i + 1;
      break;
    }
  }
  if(indexSub == -1) return;
  for(int i = indexSub, par = 0; i <= end; i++){
    if(input[i] == '(') par++;
    else if(input[i] == ')') par--;
    if(input[i] == ',' || i == end){
      if(par == 0 || i == end){
        input[i] = '\0';
        DFS(indexSub, i - 1);
        indexSub = i + 1;
      }
    }
  }
}

int main(){
  while(scanf("%s", input) == 1){
    term.clear();
    DFS(0, strlen(input) - 1);
    printf("%d\n", term.size());
  }
  return 0;
}

/*
    La estrategia es guardar todas las funciones en el set de string, aprovechando de que esta estructura de datos
    guarda solo datos unicos. Lo dificil que encontré en este problema es como sacar cada función, pensé en usar una
    pila para hacerlo iterativo pero me dí cuenta de que debia usar recursividad puesto que si se presenta el caso
    de que dentro de los argumentos de una función exista otra y esta ultima tambien la debo de tratar como si fuera
    una función nueva. Aprendí a realizar substring con arreglos char, tenia que usarlos ya que obteniendo substring
    con variables string no me estaba dando las que necesitaba para guardar.
*/