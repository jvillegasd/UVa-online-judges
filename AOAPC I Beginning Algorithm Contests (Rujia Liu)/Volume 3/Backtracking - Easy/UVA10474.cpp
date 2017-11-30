#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, Q, cases = 0, marble;
    vector<int> marbles;
    while(true){
        cin >> N >> Q;
        if(N == 0 && Q == 0) break;
        marbles.clear();
        for(int i = 0; i < N; i++){
            cin >> marble;
            marbles.push_back(marble);
        } 
        sort(marbles.begin(), marbles.end());
        cases++;
        printf("CASE# %d:\n", cases);
        for(int i = 0; i < Q; i++){
            cin >> marble;
            int index = -1;
            for(int i = 0; i < marbles.size(); i++){
                if(marbles.at(i) == marble){
                    index = i;
                    break;
                }
            }
            if(index != -1) printf("%d found at %d\n", marble, (index+1));
            else printf("%d not found\n", marble);
        }
    }
    return 0;
}