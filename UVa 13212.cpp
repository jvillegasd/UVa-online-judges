#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];
lli ans;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

int binsearch(int n, lli arr[], lli sum){
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==sum) return mid;
        if(arr[mid]<sum) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

void merge(int a[], int l, int m, int r){
    int i = l, j = m+1, bsize = 0, cnt = 0, b[1000100];
    while(i<=m && j<=r){
        if(a[i]<=a[j]) b[bsize++]=a[i++];
        else b[bsize++]=a[j++], ans+=(m-i+1);
    }
    while(i<=m) b[bsize++]=a[i++];
    while(j<=r) b[bsize++]=a[j++];
    for(int k = 0; k < bsize; k++) a[l+k] = b[k];
}

void mergesort(int a[], int l, int r){
    if(l >= r) return;
    int m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}

int main(){
    int a[1000100], n;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        ans = 0;
        mergesort(a, 0, n-1);
        printf("%lld\n", ans);
    }
    return 0;
}