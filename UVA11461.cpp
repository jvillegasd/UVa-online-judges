#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int a, b, cont;
    double square;
    while(scanf("%d %d", &a, &b) && a != 0 && b != 0){
        square = a;
        cont = 0;
        while(square <= b){
            if(sqrt(square) == (int)sqrt(square)) cont++;
            square++;
        }
        printf("%d\n", cont);
    }
    return 0;
}