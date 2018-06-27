#include <stdio.h>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    cin.get();
    while(n--){
        string input;
        getline(cin, input);
        stack<char> pila;
        for(int i = 0; input[i]; i++){
            if(!pila.empty() && input[i] == ')' && pila.top() == '(') pila.pop();
            else if(!pila.empty() && input[i] == ']' && pila.top() == '[') pila.pop();
            else if(input[i] != ' ') pila.push(input[i]);
        }
        if(pila.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
    La condicion para poder quitar el par de parentesis es que uno este inmediatamente uno al lado del otro, es por eso
    que uso una pila, mis primeras soluciones era simplemente un contador que sumaba si encontraba "( o [" y restaba
    cuando encontraba ") o ]", si ese contado al final daba cero es decir que si esta balanceado pero como no tenia
    en cuenta la regla de que deben de estar inmediatamente al lado, entonces me mandaba WA. Me llevo tiempo pensar
    en otra solucion porque el enunciado no es claro para mi.
    Ejemplo:
    ([)] no es posible debido a que "[" no tiene su contraparte de inmediado, para que sea posible tiene que ser
    asi: ([]).
*/