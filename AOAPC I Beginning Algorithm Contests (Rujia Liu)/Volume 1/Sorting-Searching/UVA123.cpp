#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> ignored;

bool isntIgnored(string word){
    for (int i = 0; i < ignored.size(); i++) {
        if (ignored.at(i).c_str() == word) return false;
    }
    return true;
}

string toUpper(string word){
    for (int i = 0; i < word.size(); i++) word[i] = toupper(word[i]);
    return word;
}

string toLower(string word){
    for (int i = 0; i < word.size(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    return word;
}

int main(){
    multimap<string, string> KWIC;
    string line, word;
    while (true) {
        cin >> line;
        if (line == "::") break;
        ignored.push_back(line);
    }
    getline(cin, line);
    while (getline(cin, line)){
        line = toLower(line);
        for (int i = 0; i < line.size(); i++){
            if (isalpha(line[i])){
                string word = "";
                while (isalpha(line[i])){
                    word += line[i];
                    i++;
                }
                if (isntIgnored(word))
                {
                    string auxLine = line;
                    word = toUpper(word);
                    auxLine = auxLine.replace(i - word.size(), word.size(), word);
                    KWIC.insert(make_pair(word, auxLine));
                }
            }
        }
    }
    for (auto iterator = KWIC.begin(); iterator != KWIC.end(); iterator++){
        cout << iterator->second << endl;
    }
    return 0;
}