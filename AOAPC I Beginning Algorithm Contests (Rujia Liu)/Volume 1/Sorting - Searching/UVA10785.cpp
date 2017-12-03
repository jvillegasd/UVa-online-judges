#include <iostream>
#include <algorithm>

using namespace std;

const char table[]="AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR";

int main(){

    int N, L, cases = 0;
    cin >> N;
    while(N-- > 0){
        cin >> L;
        char ans[300];
        char vo[200];
        char co[200];
        int index;
        index = 0;
        for(int i = 1; i < L; i+=2){
            co[index++] = table[i];           
        }
        co[index] = '\0';
        sort(co, co+index);
        index = 0;
        for(int i = 0; i < L; i+=2){
            vo[index++] = table[i];
        }
        vo[index] = '\0';
        sort(vo, vo+index);
        index = 0;
        for(int i = 1; i < L; i+=2){
            ans[i] = co[index++];
        }
        index = 0;
        for(int i = 0; i < L; i+=2){
            ans[i] = vo[index++];
        }
        ans[L] = '\0';
        cases++;
        printf("Case %d: %s\n", cases, ans);
    }
    return 0;
}