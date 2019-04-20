#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int testCase;
    long long K, N;
    cin >> testCase;
    while(testCase-- > 0){
        cin >> K;
        K = abs(K);
        N = ceil((sqrt(1+8*K)-1)/2);
        if(K == 0) cout << 3 << endl;
        else if(N*(N+1)/2 == K) cout << N << endl;
        else{
            for(long long i = N;; i++){
                if((i*(i+1)/2 - K)%2 == 0){ //Caso cuando la formula da diferente de K
                    cout << i << endl;
                    break;
                }
            }
        }
        if(testCase != 0) printf("\n");
    }
    return 0;
}
/*Formulas:
    (1) n(n+1)/2 = K
    (2) n(n+1)/2 - K = 2b
    (4) n = (sqrt(1+8*K)-1)/2
    Para hallar (2):
      Se tiene que n(n+1)/2 = Z (3), donde Z <> K. Se reexpresa Z, entonces: Z = a + b. La sumatoria actual para que
      de K se necesita que tenga terminos restandose, entonces, K = a - b. Reemplazando estas ecuaciones en (3) se 
      obtiene (2).
*/ 