#include <iostream>

using namespace std;

int main(){
    int n, cont, L;
    cin >> n;
    while(n-- > 0){
        cin >> L;
        int vector[L];
        for(int i = 0; i < L; i++) cin >> vector[i];
        cont = 0;
        for(int i = 0; i < L; i++){
            for(int j = i + 1; j < L; j++){
                if(vector[i] > vector[j]){
                    swap(vector[i], vector[j]);
                    cont++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", cont);
    }
    return 0;
}