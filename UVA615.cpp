#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> graph[1000];
map<int, int> inDegree;
map<int, int> newLabel;
int visited[1000], V = 0, root, specialCase;

void DFS(int node){
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++) if(!visited[graph[node][i]]) DFS(graph[node][i]);
}

void cleanAll(){
    for(int i = 0; i < 1000; i++) graph[i].clear();
    inDegree.clear();
    newLabel.clear();
    V = 0;
    specialCase = 1;
    memset(visited, false, sizeof(visited));
}

bool isNotTree(){
    int noRoot = 0;
    bool oneInDegree = true;
    for(map<int, int>::iterator it = inDegree.begin (); it != inDegree.end (); it++){
        if((*it).second == 0) root = (*it).first, noRoot++;
        else if((*it).second > 1) oneInDegree = false;
    }
    return noRoot > 1 || noRoot == 0 || !oneInDegree;
}

bool isConnected(){
    DFS(root);
    for(int i = 1; i < V; i++) if(!visited[i]) return false;
    return true;
}

int main(){
    int src, fnal, tstCase;
    while(scanf("%d %d", &src, &fnal))
    {
        if(src < 0 && fnal < 0) break;
        if(src == 0 && fnal == 0){
            tstCase++;
            if(specialCase){ //src == 0 && fnal == 0 as unique case
                printf("Case %d is a tree.\n", tstCase);
                continue;
            }
            if(isNotTree()){
                printf("Case %d is not a tree.\n", tstCase);
                cleanAll();
                continue;
            }
            if(!isConnected()) printf("Case %d is not a tree.\n", tstCase);
            else printf("Case %d is a tree.\n", tstCase);
            cleanAll();
        } else{
            if(!newLabel[src]) V++, newLabel[src] = V, inDegree[newLabel[src]] = 0;
            if(!newLabel[fnal]) V++, newLabel[fnal] = V, inDegree[newLabel[fnal]] = 0;
            graph[newLabel[src]].push_back(newLabel[fnal]);
            inDegree[newLabel[fnal]]++;
            specialCase = 0;
        }
    }
    return 0;
}