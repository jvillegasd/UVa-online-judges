#include <iostream>
#include <string>

using namespace std;

int main(){
    int testCase, n, cases = 0;
    string input;
    bool isSymmetric;
    cin >> testCase;
    getline(cin, input);
    while(cases < testCase){
        getline(cin, input);
        n = stoi(input.substr(3, input.size()));
        isSymmetric = true;
        long long int matriz[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matriz[i][j];
                if(matriz[i][j] < 0) isSymmetric = false;
            }
        }
        if(isSymmetric){
            for(int i = 0; i < n & isSymmetric; i++){
                for(int j = 0; j < n; j++){
                    if(matriz[i][j] != matriz[n-1-i][n-1-j]) isSymmetric = false;
                }
            }
        }
        if(isSymmetric) printf("Test #%d: Symmetric.\n", cases + 1);
        else printf("Test #%d: Non-symmetric.\n", cases + 1);
        cases++;
        getline(cin, input);
    }
    return 0;
}