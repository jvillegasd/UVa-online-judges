#include <iostream>

using namespace std;

int main(){
    int n, f, size, animals, ef;
    long long  sum;
    cin >> n;
    while(n-- > 0){
        cin >> f;
        sum = 0;
        while(f-- > 0){
            cin >> size >> animals >> ef;
            sum += size*ef;
        }
        cout << sum << endl;
    }
    return 0;
}