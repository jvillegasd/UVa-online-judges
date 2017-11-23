#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, numero;
    while(true){
        cin >> n;
        int personas[n];
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >>personas[i];
        }
        sort(personas, personas+n);
        for(int i = 0; i < n; i++){
          if(i != n - 1){
              cout << personas[i] << " ";
          } else cout << personas[i];
        }
        cout << "\n";
    }
    return 0;
}