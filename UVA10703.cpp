#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int w, h, n, x1, x2, y1, y2, cont;
    bool matriz[507][507];
    while(true){
        cin >> w >> h >> n;
        if(w == 0 && h == 0 && n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            for(int j = y1 - 1; j <= y2 - 1; j++){
                for(int k = x1 - 1; k <= x2 - 1; k++) matriz[j][k] = true;
            }
        }
        cont = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!matriz[i][j]) cont++;
                else matriz[i][j] = false;
            }
        }
        if(cont == 0) printf("There is no empty spots.\n");
        else if(cont == 1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n", cont);
    }
    return 0;
}