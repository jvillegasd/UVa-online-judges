#include <bits/stdc++.h>

using namespace std;

vector<string> g;
bool vist[9][9];
int posI[] = {-1, 0, 0}, posJ[] = {0, -1, 1}, n, m;

bool words(char l){
    return l == 'I' || l == 'E' || l == 'H' || l == 'O' || l == 'V' || l == 'A' || l == '#';
}

void DFS(int i, int j, int spc){
    vist[i][j] = true;
    if(g[i][j] == '#') return;
    if(spc) printf(" ");
    for(int k = 0; k < 3; k++){
        int nI = i + posI[k];
        int nJ = j + posJ[k];
        if(nI >= 0 && nI < n && nJ >= 0 && nJ < m && !vist[nI][nJ] && words(g[nI][nJ])){
            if(k == 0) printf("forth");
            if(k == 1) printf("left");
            if(k == 2) printf("right");
            DFS(nI, nJ, 1);
        } 
    }
}

int main(){
    int tc;
    string inp;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        g.clear();
        memset(vist, false, sizeof(vist));
        for(int i = 0; i < n; i++) cin >> inp, g.push_back(inp);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(g[i][j] == '@') DFS(i, j, 0);
        printf("\n");
    }
    return 0;
}