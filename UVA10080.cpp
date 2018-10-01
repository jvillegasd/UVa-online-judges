#include <stdio.h>

using namespace std;

int gx[150], gy[150], hx[150], hy[150];
//Matching y Maximum flow - Algorithmist
int main(){
    int n, m, s, v;
    scanf("%d %d %d %d", &n, &m, &s, &v);
    for(int i = 0; i < n; i++) scanf("%d %d", &gx[i], &gy[i]);
    for(int i = 0; i < m; i++) scanf("%d %d", &hx[i], &hy[i]);
    return 0;
}