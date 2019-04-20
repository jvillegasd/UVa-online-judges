#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isPalindrome(string palindrome){
    for(int i = 0; i < palindrome.size(); i++){
        if(palindrome[i] != palindrome[palindrome.size() - 1 - i]) return false;
    }
    return true;
}

int main(){
    string input;
    int cont;
    while(getline(cin, input)){
        cont = 0;
        map<string, int> usedPal;
        for(int i = 0; i < input.size(); i++){
            string palindrome = "";
            for(int j = i; j < input.size(); j++){
                palindrome+=input[j];
                if(isPalindrome(palindrome) && usedPal.find(palindrome) == usedPal.end()){
                    cont++;
                    usedPal[palindrome]+=1;
                }
            }
        }
        cout << "The string '" << input << "' contains " << cont << " palindromes.\n";
    }
    return 0;
}