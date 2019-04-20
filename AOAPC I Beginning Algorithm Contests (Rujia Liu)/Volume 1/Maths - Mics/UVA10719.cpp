#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    int k;
    while(scanf("%d", &k) == 1){
        cin.get();
        string polinomyS;
        vector<long int> polinomy;
        getline(cin, polinomyS);
        stringstream ss(polinomyS);
        long int quotient;
        while(ss >> quotient) polinomy.push_back(quotient);
        for(int i = 1; i < polinomy.size(); i++) polinomy[i] += polinomy[i - 1] * k;
        printf("q(x):");
        for(int i = 0; i < polinomy.size() - 1; i++) printf(" %d", polinomy[i]);
        printf("\nr = %d\n\n", polinomy[polinomy.size() - 1]);
    }
    return 0;
}