#include <bits/stdc++.h>

using namespace std;

bool visited[26][26];
int posI[]={1, 1, 1, 0, 0, -1, -1, -1};
int posJ[]={1, 0, -1, 1, -1, 1, 0, -1};
int n, tc = 0;
vector<string> warzone;
string input;

void DFS(int i, int j){
    visited[i][j] = true;
    for(int k = 0; k < 8; k++){
        int newI = i + posI[k];
        int newJ = j + posJ[k];
        if(newI >= 0 && newI < n && newJ >= 0 && newJ < n && !visited[newI][newJ] && warzone[newI][newJ] == '1') DFS(newI, newJ);
    }
}

int main(){
    int cont = 0;
    while(scanf("%d", &n) != EOF){
        tc++;
        warzone.clear();
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++){
            cin >> input;
            warzone.push_back(input);
        }
        cont = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) if(warzone[i][j] == '1' && !visited[i][j]) DFS(i, j), cont++;
        }
        printf("Image number %d contains %d war eagles.\n", tc, cont);
    }
    return 0;
}