#include <iostream>
#include <vector>
#include <string>

using namespace std;

string toLower(string word){
    for(int i = 0; word[i] > 0; i++){
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    }
    return word;
}

int incidence(string sentence, string *keywords, int K){
    int inci = 0;
    for(int i = 0; i < K; i++){
        int index = sentence.find(keywords[i]);
        int length = keywords[i].length();
        while(index < sentence.length()){
            if(index + length < sentence.length()){
                if(!isalpha(sentence[index + length])) inci++;
            } else if(index + length == sentence.length()){
                inci++;
                break;
            }
            index = sentence.find(keywords[i], index + 1);
        }
    }
    return inci;
}

int main(){
    int K, E, max, set = 0;
    while(cin >> K >> E){
        string *keywords = new string[K];
        max = 0;
        vector<string> excuses;
        string sentence, lsentence;
        getline(cin,sentence);
        for(int i = 0; i < K; i++){
            getline(cin, keywords[i]);
            keywords[i] = toLower(keywords[i]);
        }
        for(int i = 0; i < E; i++){
            getline(cin, sentence);
            lsentence = toLower(sentence);
            int inc = incidence(lsentence, keywords, K);
            if(inc > max){
                excuses.clear();
                max = inc;
                excuses.push_back(sentence);
            }else if(inc == max) excuses.push_back(sentence);
        }
        set++;
        cout << "Excuse Set #" << set << endl;
        for(int i = 0; i < excuses.size(); i++) cout << excuses[i] << endl;
        cout << endl;
        delete[] keywords;
    }
    return 0;
}