#include <iostream>
#include <string>

using namespace std;

int main(){
    char database[256];
    database['A']='A';
    database['E']='3';
    database['H']='H';
    database['I']='I';
    database['J']='L';
    database['L']='J';
    database['M']='M';
    database['O']='O';
    database['S']='2';
    database['T']='T';
    database['U']='U';
    database['V']='V';
    database['W']='W';
    database['X']='X';
    database['Y']='Y';
    database['Z']='5';
    database['1']='1';
    database['2']='S';
    database['3']='E';
    database['5']='Z';
    database['8']='8';
    string input, auxP, auxM;
    bool palindrome, mirrored;
    while(getline(cin, input)){
        if(input.length() == 0) break;
        auxP = "";
        auxM = "";
        palindrome = false;
        mirrored = false;
        for(int i = input.length() - 1; i >= 0; i--){
            auxP += input[i];
            if(database[input[i]] != ' ') auxM += database[input[i]];
        }
        if(auxP == input) palindrome = true;
        if(auxM == input) mirrored = true;
        if(!palindrome && !mirrored) cout << input << " -- is not a palindrome." << endl;
        else if(palindrome && !mirrored) cout << input << " -- is a regular palindrome." << endl;
        else if(mirrored && !palindrome) cout << input << " -- is a mirrored string." << endl;
        else cout << input << " -- is a mirrored palindrome." << endl;
        if(input.length() != 0) cout << endl;
    }
    return 0;
}