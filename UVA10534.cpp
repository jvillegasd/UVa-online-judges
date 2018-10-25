#include <bits/stdc++.h>

using namespace std;
//http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html#3

int n, num[10000], lis[10000], lds[10000];
vector<int> v;

void LIS(){
    int size = 1;
    v.push_back(num[0]);
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (num[i] > v.back())
        {
            v.push_back(num[i]);
            lis[i] = ++size;
        }
        else
        {
            int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
            v[temp] = num[i];
            lis[i] = temp + 1;
        }
    }
}

void LDS(){
    int size = 1;
    v.push_back(num[n - 1]);
    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (num[i] > v.back())
        {
            v.push_back(num[i]);
            lds[i] = ++size;
        }
        else
        {
            int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
            v[temp] = num[i];
            lds[i] = temp + 1;
        }
    }
}

int main(){
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++) scanf("%d", &num[i]);
        v.clear();
        LIS();
        v.clear();
        LDS();
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = min(lis[i], lds[i]);
            if (max < temp) max = temp;
        }
        printf("%d\n", 2 * max - 1);
    }
    return 0;
}
/*
    La estrategia es usar una combinacion de LIS (Longest Increasing Sequence) y LDS (Longest Decreasing Sequence).
    Ir iterando por todo el vector de LIS y LDS buscando el minimo entre ellos dos, luego, con ese numero, ver
    si es el maximo. Todo esto se hace para buscar el n central de toda la secuencia
*/