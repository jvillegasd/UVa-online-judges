#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, t;
    int cont;
    while(cin >> s >> t){
        cont = 0;
        for(int i = 0; t[i] && cont < s.size(); i++){
            if(s[cont] == t[i]) cont++;
        }
        if(cont == s.size()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}