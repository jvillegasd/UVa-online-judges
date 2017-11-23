#include <iostream>
#include <string>

using namespace std;    //Usar array del alfabeto para indicar que palabras se usan y optimizar la busqueda

int main(){
    int round = 1, bl, gl, glA;
    string word, input;
    while(true){
        cin >> round;
        if(round == -1) break;
        cin >> word >> input;
        bl = 0;
        gl = 0;
        glA = 0;
        int alph[27] = {0};
        for(int i = 0; i < word.length(); i++){ //Marcar que letras del alfabeto usa la solucion
            if(alph[word[i]-'a'] == 0){
              alph[word[i]-'a'] = 1;
              glA +=1;                         //Ver cuantas letras usa (No tener en cuenta las repetidas)
            }
        }
        cout << "Round " << round << endl;
        for(int i = 0; i < input.length() && bl < 7; i++){
            if(alph[input[i]-'a'] == 0){
                bl++;
                alph[input[i]-'a'] = 2;
            }
            else if(alph[input[i]-'a'] == 1){
                gl++;
                alph[input[i]-'a'] = 2;
            }
        }
        if(gl == glA) cout << "You win." << endl;
        else if(bl >= 7) cout << "You lose." <<endl;
        else cout << "You chickened out." << endl;
    }
    return 0;
}