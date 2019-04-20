#include<bits/stdc++.h>

using namespace std;

int parent[900];

void makeSet(int n){
    for(int i = 0; i < n; i++) parent[i] = i;
}

int find(int i){
    if(parent[i] == i) return i;
    return find(parent[i]);
}

bool sameSet(int i, int j){
    return find(i) == find(j);  
}

void unionSet(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    parent[iRoot] = jRoot;
}

int main(){
    int tc, n, u, v, yes, no;
    char request;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        getchar();
        yes = no = 0;
        makeSet(n);
        while((request = getchar()) && isalpha(request)){
            scanf("%d %d", &u, &v);
            getchar();
            if(request == 'c') unionSet(u-1, v-1);
            else {
              if(sameSet(u-1, v-1)) yes++;
              else no++;
            }
        }
        printf("%d,%d\n", yes, no);
        if(tc) printf("\n");
    }
    return 0;
}