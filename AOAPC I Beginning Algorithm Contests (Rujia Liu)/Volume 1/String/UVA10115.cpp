#include <string>
#include <iostream>

using namespace std;

int main(){
    int n;
    string cWord;
    while(true){
        cin >> n;
        if (n == 0) break;
        int cont = 0;
        getline(cin, cWord);
        string words[300];
        string rWords[300];
        while(cont < n){
            getline(cin, words[cont]);
            getline(cin, rWords[cont]);
            cont++;
        }
        getline(cin, cWord);
        for(int i = 0; i < n; i++){
            int length = words[i].size();
            while(true){
                int index = cWord.find(words[i]);
                if(index == -1) break;
                cWord.replace(index, length, rWords[i]);
            }
        }
        cout << cWord << endl;
    }
    return 0;
}