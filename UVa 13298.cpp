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
#define MOD 1000000009

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];
lli bc[110];

struct matrix{
    int row, col;
    lli m[110][110];
};

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

matrix mul(matrix a, matrix b){
    matrix ans;
    ans.row = a.row;
    ans.col = b.col;
    for(int i = 0; i < a.row; i++){
        for(int j = 0; j < b.col; j++){
            ans.m[i][j] = 0;
            for(int k = 0; k < a.col; k++){
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
                ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}

matrix mPow(matrix a, lli p){
    if(p==1) return a;
    if(p&1) return mul(a, mPow(a, p-1));
    matrix ans = mPow(a, p>>1);
    return mul(ans, ans);
}

void setBC(int k){
    bc[0] = 1;
    for(int i = 1; i < 110; i++){
        bc[i] = 0;
        int aux = k;
        for(int j = i-1; j >= 0 && aux; j--, aux--) bc[i]=(bc[i]+bc[j])%MOD;
    }
}

int main(){
    int k;
    lli sum, n;
    while(scanf("%d %lld", &k, &n) == 2){
        if(!k && !n) break;
        setBC(k);
        matrix trans;
        trans.row = trans.col = k;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                trans.m[i][j] = 0;
                if(i==0 || i==j+1) trans.m[i][j] = 1;
            }
        }
        if(n<=k) printf("%lld\n", bc[n]);
        else{
            trans = mPow(trans, n-k+1);
            sum = 0;
            for(int i = 0; i < k; i++) sum+=(trans.m[0][i]*bc[k-i-1])%MOD, sum%=MOD;
            printf("%lld\n", sum);
        }
    }
    return 0;
}
