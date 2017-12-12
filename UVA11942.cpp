#include <stdio.h>

using namespace std;

int main(){
    bool asc, desc;
    int n, lj[21];
    scanf("%d", &n);
    printf("Lumberjacks:\n");
    while(n-- > 0){
        asc = desc = false;
        for(int i = 0; i < 10; i++) scanf("%d", &lj[i]);
        for(int i = 0; i < 9; i++){
            if(lj[i] > lj[i + 1]) desc = true;
            else asc = true;
        }
        if(asc && desc) printf("Unordered\n");
        else printf("Ordered\n");
    }
    return 0;
}