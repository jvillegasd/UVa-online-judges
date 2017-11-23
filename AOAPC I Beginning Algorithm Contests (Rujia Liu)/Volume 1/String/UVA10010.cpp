#include <iostream>
#include <cstring>

using namespace std;

int m, n;
const int dir[][2] = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1}};
char wordSoup[60][60];
bool found;

void toLower(char word[]){
    for(int i = 0; word[i] > 0; i++){
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    }
}

void foundWord(int i, int j, char wordArray[60]){
    for(int k = 0; k < 8; k++){
        int ni = i;
        int nj = j;
        int waI = 0;
        while(wordSoup[ni][nj] == wordArray[waI]){
            ni += dir[k][0];
            nj += dir[k][1];
            waI++;
            if(wordArray[waI] == '\0'){
                found = true;
                return;
            }
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) break;
        }
    }
}

int main(){
    int cases, words;
    cin >> cases;
    while(cases-- > 0){
        cin >> m >> n;
        memset(wordSoup, ' ', sizeof(wordSoup[0][0])*60*60);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) cin >> wordSoup[i][j];
            toLower(wordSoup[i]);
        }
        cin >> words;
        char wordArray[60];
        cin.getline(wordArray, 60);
        for(int k = 0; k < words; k++){
            cin.getline(wordArray,60);
            toLower(wordArray);
            found = false;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(wordSoup[i][j] == wordArray[0]){
                        foundWord(i, j, wordArray);
                        if(found){ 
                          cout << (i + 1) << " " << (j + 1) << endl;
                          break;
                        }
                    }
                }
                if(found) break;
            }
        }
        if(cases != 0) cout << endl;
    }
    return 0;
}