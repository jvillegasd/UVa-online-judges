#include <stdio.h>
#include <math.h>

using namespace std;

int binarySearch(int a, int w){
    int mid, l, r;
    double quotient=log(a)/log(w);
    l=1, r=2147483645, mid=(l+r)/2;
    while(l!=r){
        if(log(mid+1)/log(mid)-quotient>0.000000000001) l=mid+1;
        else if(log(mid+1)/log(mid)-quotient<-0.000000000001) r=mid;
        else break;
        mid=(l+r)/2;
    }
    return mid;
}

int main(){
    int a, w;
    while(scanf("%d %d", &a, &w)!=EOF){
        if(a==0 && w==0) break;
        int n=binarySearch(a, w), x=round(log(a)/log(n+1)), mul=1;
        long long int notWork=0, totalH=0;
        for(int i=0; i<x;i++){
            notWork+=mul;
            totalH+=(mul*a);
            a/=(n+1);
            mul*=n;
        }
        printf("%lld %lld\n", notWork, totalH+mul);
    }
    return 0;
}
/*
    Teniendo en cuenta la sumatoria de la altura total:
                    totalH = a + a*N/(N+1) + (a*N^2)/(N+1)^2 + ... + (a*N^(x-1))/(N+1)^(x-1) + N^x (1)
    podemos darnos cuenta en (1) que el ultimo sumando nos dice que cuando se llega al "nivel" x se presenta
    la siguiente situacion -> a = (N+1)^x, por lo que llegamos al nivel donde se encuentra los gatos que trabajaran.
    De la anterior deduccion obtenemos las siguientes formulas:
                                            w = N^x (2)
                                            a = (N+1)^x (3)
    Usé busqueda binaria para tantear el valor de N, tener en cuenta el error, debe ser de 1e-12, sino te puede joder
    en algunos casos, por ultimo, para hallar el valor de x es conveniente usar (3) debido a casos especiales cuyo
    despeje de esta variable usando (2) da division 0/0.
*/