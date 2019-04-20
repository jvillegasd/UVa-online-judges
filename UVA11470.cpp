#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double n, grid[11][11];
    int  tc = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        printf("Case %d: ", tc+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin >> grid[i][j];
        }
        int i = 0, j = 0, iF = n, jF = n, sum;
        for(int s = 0; s < ceil(n/2); s++){
            sum = 0;
            if(i == iF - 1 && j == jF - 1){
                cout << grid[i][j] << endl;
                break;
            }
            for(int k = j; k < jF; k++) sum += grid[i][k];
            for(int k = j; k < jF; k++) sum += grid[iF - 1][k];
            for(int k = i + 1; k < iF - 1; k++) sum += grid[k][j];
            for(int k = i + 1; k < iF - 1; k++) sum += grid[k][jF - 1];
            i++;
            iF--;
            j++;
            jF--;
            cout << sum;
            if(s != ceil(n/2) - 1) cout << " ";
            else cout << endl;
        }
        tc++;
    }
    return 0;
}