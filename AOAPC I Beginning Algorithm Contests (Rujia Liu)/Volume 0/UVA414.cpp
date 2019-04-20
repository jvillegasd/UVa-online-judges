#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, maxX, auxRow, sum;
    while(true){
        cin >> N;
        int ansArray[N];
        string digitalImg;
        getline(cin, digitalImg);
        if(N == 0) break;
        maxX = 0;
        sum = 0;
        for(int i = 0; i < N; i++){
            auxRow = 0;
            getline(cin, digitalImg);
            for(int j = 0; j < digitalImg.length(); j++){
                if(digitalImg[j] == 'X') auxRow++;
            }
            ansArray[i] = auxRow;
            maxX = max(maxX, auxRow);
        }
        for(int i = 0; i < N; i++) sum = sum + (maxX - ansArray[i]);
        cout << sum << endl;
    }
    return 0;
}