#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int vector[30];
    int cont, number;
    string line;
    stringstream ss;
    while(getline(cin, line)){
        cont = 0;
        ss.clear();
        ss.str(line);
        while(ss >> number){
            vector[cont] = number;
            cont++;
            printf("%d ", number);
        }
        printf("\n");
        for(int i = cont - 1; i >= 0; i--){
            int maxN = -1;
            int index;
            for(int j = 0; j <= i; j++){
                if(vector[j] > maxN){
                    index = j;
                    maxN = vector[j];
                }
            }
            if(i != index){
                if(index != 0){
                    printf("%d ",cont - index);
                    for(int k = 0; k <= index/2; k++) swap(vector[k], vector[index - k]);
                }
                printf("%d ", cont - i);
                for(int k = 0; k <= i/2; k++) swap(vector[k], vector[i - k]);
            }
        }
        printf("%d\n", 0);
    }
}