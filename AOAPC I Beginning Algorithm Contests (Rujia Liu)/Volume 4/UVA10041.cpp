#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n, streets[510], optimalStreet, len, sum;
    scanf("%d", &n);
    while(n-- > 0){
        sum = 0;
        scanf("%d", &len);
        for(int i = 0; i < len; i++) scanf("%d", &streets[i]);
        sort(streets, streets + len);
        optimalStreet = len / 2;
        for(int i = 0; i < len; i++) sum += abs(streets[optimalStreet] - streets[i]);
        printf("%d\n", sum);
    }
    return 0;
}
/*
    La estrategia es buscar la calle que este en la mitad, ya que se quiere minimizar las distancias entre las casas,
    la unica manera es que Vito viva en la mitad de la calle.
*/