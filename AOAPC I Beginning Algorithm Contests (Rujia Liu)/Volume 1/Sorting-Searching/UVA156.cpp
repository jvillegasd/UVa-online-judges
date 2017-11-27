#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string toLowerAndSort(string word){
    for(int i = 0; i < word.size(); i++) if(word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    sort(word.begin(), word.end());
    return word;
}

int main(){
    map<string,int> anagrams;
    vector<string> dic;
    string line;
    while(true){
        cin >> line;
        if(line == "#") break;
        dic.push_back(line);
        anagrams[toLowerAndSort(line)] += 1;
    }

    sort(dic.begin(), dic.end());
    for(int i = 0; i < dic.size(); i++){
        if(anagrams[toLowerAndSort(dic[i])] == 1) printf("%s\n", dic[i].c_str());
    }
    return 0;
}