#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int year, k, n, numM;
    double num;
    while(scanf("%d", &year) && year != 0){
        num = 0;
        k = (year - 1960) / 10 + 2;
        numM = pow(2, k);
        n = 0;
        while(num < numM){
            n++;
            num+= log2(n);
        }
        n--;
        printf("%d\n", n);
    }
    return 0;
}
/*
    El numero mas grande es 2^k donde "k" son los bits del pc, para saber el numero mas grande que puede tener
    la pc (del problema): numM = 2^(2+[(year - 1960)/10]). Teniendo en cuenta que 2^k > n! (solo piden que sea uInt),
    hacemos algo de algebra quedaria k > log2(n!) y si re-expresamos el factorial: k > log2(n)+log2(n-1)+...+log2(1),
    como sabemos que 2^k > k, entonces 2^k > log2(n)+log2(n-1)+...+log2(1) (Se hace esto para hacer menos calculo).
*/