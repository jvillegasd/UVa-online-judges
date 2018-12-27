#include <bits/stdc++.h>

using namespace std;

bool vist[101][101];
int nI[] = {-1, 1, 0, 0}, nJ[] = {0, 0, 1, -1};
int n;
vector<string> g;

void DFS(int i, int j){
    vist[i][j] = true;
    g[i][j] = '.';
    for(int k = 0; k < 4; k++){
        int ik = i + nI[k];
        int jk = j + nJ[k];
        if(ik < n && ik >= 0 && jk < n && jk >= 0 && (g[ik][jk] == 'x' || g[ik][jk] == '@')) DFS(ik, jk);
    }
}

int main(){
    int tc, cont = 0, ans;
    string inp;
    scanf("%d", &tc);
    while(cont < tc){
        scanf("%d", &n);
        ans = 0;
        g.clear();
        memset(vist, false, sizeof(vist));
        for(int i = 0; i < n; i++) cin >> inp, g.push_back(inp);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(g[i][j] == 'x') DFS(i, j), ans++;
        printf("Case %d: %d\n", ++cont, ans);
    }
    return 0;
}