#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n;
    map<string, int> db;  //A map sorts its keys internally
    string line, country;
    cin >> n;
    getline(cin, line);
    while(n-- > 0){
        cin >> country;
        getline(cin, line);
        db[country] +=1;
    }
    for(auto iterator = db.begin(); iterator != db.end(); iterator++){
        cout << iterator->first << " " << iterator->second << endl;
    }
}