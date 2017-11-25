#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n = 1, strongH, weakH, game = 0;
    string code, guess = "", codeCopy;
    vector<string> guessV;
    while(true){
        cin >> n;
        if(n == 0) break;
        getline(cin, code); //Consume new line
        getline(cin, code);
        while(true){
            getline(cin, guess);
            if(guess[0] == '0') break;
            guessV.push_back(guess);
        }
        game++;
        printf("Game %d:\n", game);
        for(int i = 0; i < guessV.size(); i++){
            strongH = 0;
            weakH = 0;
            codeCopy = code;
            for(int j = 0; j < code.size(); j++){
                if(codeCopy[j] == ' ') continue;
                if(codeCopy[j] == guessV.at(i).at(j)){
                    strongH++;
                    guessV.at(i).at(j) = '.';
                    codeCopy[j] = '.';
                    continue;
                }
            }
            for(int j = 0; j < code.size(); j++){
                if(codeCopy[j] == ' ' || codeCopy[j] == '.') continue;
                for(int k = 0; k < code.size(); k++){
                    if(codeCopy[j] == guessV.at(i).at(k)){
                        weakH++;
                        guessV.at(i).at(k) = '.';
                        break;
                    }
                }
            }
            printf("    (%d,%d)\n", strongH, weakH);
        }
        guessV.clear();
    }
    return 0;
}