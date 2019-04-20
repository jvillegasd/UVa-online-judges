#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char toLower(char letter){
    if(letter >= 'A' && letter <= 'Z') letter += 32;
    return letter;
}

int main(){
    string line, word;
    vector<string> words;
    while(getline(cin, line)){
        word = "";
        for(int i = 0; i <= line.length(); i++){
            if(isalpha(line[i])) word += toLower(line[i]);
            else if(word != ""){
              words.push_back(word);
              word = "";
            }
        }
    }
    sort(words.begin(), words.end());
    cout << words[0] << endl;
    for(int i = 1; i < words.size(); i++) if(words[i-1] != words[i]) cout << words[i] << endl;
    return 0;
}