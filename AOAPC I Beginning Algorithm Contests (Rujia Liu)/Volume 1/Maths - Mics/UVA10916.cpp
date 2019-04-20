#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int year, exp, n, bit;
    double num;
    while(scanf("%d", &year) && year != 0){
        num = 0;
        exp = (year - 1960) / 10 + 2;
        bit = pow(2, exp);
        n = 0;
        while(num < bit){
            n++;
            num+= log2(n);
        }
        n--;
        printf("%d\n", n);
    }
    return 0;
}
/*
    El numero mas grande es 2^k donde "k" es el numero de bits, en este ejercicio k = 2^[(year-1960)/10]+2. Del
    ejercicio tenemos que 2^k > n!, entonces, aligerando calculos la condicion quedaria asi: 
    k > log2(n) + log2(n-1) + ... + log2(1).
*/