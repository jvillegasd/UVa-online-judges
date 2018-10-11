#include <bits/stdc++.h>

using namespace std;

int parent[26], sets = 0, size[26];
vector<pair<int,int > > edges;

void makeSet(){
    for(int i = 0; i < 26; i++) parent[i] = i;
}

int find(int i){
    if(i == parent[i]) return i;
    return find(parent[i]);
}

bool sameSet(int i, int j){
    return find(i) == find(j);
}

void unionSet(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    parent[iRoot] = jRoot;
    size[jRoot]+=size[iRoot];
    sets--;
}

int main(){
    int tc, acorns = 0;
    char input[100];
    scanf("%d", &tc);
    while(tc--){
        edges.clear();
        sets = acorns = 0;
        memset(size, 0, sizeof(size));
        memset(input, 0, sizeof(input));
        makeSet();
        while(scanf("%s", input) && input[0] != '*') edges.push_back(make_pair(input[1]-'A', input[3]-'A'));
        scanf("%s", input);
        for(int i = 0; input[i]; i+=2) if(input[i]-'A' >= 0 && input[i]-'A' < 26) size[input[i]-'A'] = 1, sets++;
        for(pair<int,int> p : edges) if(!sameSet(p.first, p.second)) unionSet(p.first, p.second);
        for(int i = 0; i < 26; i++) if(parent[i] == i && size[i] == 1) acorns++;
        printf("There are %d tree(s) and %d acorn(s).\n", sets - acorns, acorns);
    }
    return 0;
}