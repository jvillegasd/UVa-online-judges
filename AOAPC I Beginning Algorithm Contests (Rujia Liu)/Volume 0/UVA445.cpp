#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int cont;
    char mazeString[200];
    while(cin.getline(mazeString, 200)){
        for(int i = 0; mazeString[i] > 0; i++){ //Con mazeString[i] > 0 miro si ese char no es nulo (ASCII)
            if(mazeString[i]>='0' && mazeString[i]<='9') cont+= mazeString[i]-'0'; //Adapto el num ASCII
            else{
                for(int j = 0; j < cont; j++) {
                    if(mazeString[i] == 'b') cout << " ";
                    else cout << mazeString[i];
                }
                cont=0;
            }
            if(mazeString[i]=='!'){ //Indica que hasta ahi llega la fila
                cout << endl;
                cont = 0;
            } 
        }
        cout << endl;
    }
    return 0;
}