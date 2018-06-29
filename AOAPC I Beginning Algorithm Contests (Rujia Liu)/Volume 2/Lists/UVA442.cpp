#include <stdio.h>
#include <stack>
#include <map>

using namespace std;

map<char, pair<int, int>> matrixM;

struct matrix{
    char name;
    int row, col;
    
    void setValues(char name, int row, int col){
        this->name = name;
        this->row = row;
        this->col = col;
    }
};

void solve(char input[]){
    stack<matrix> pila;
    bool error = false;
    int ans = 0;
    for(int i = 0; input[i]; i++){
        if(input[i] == '(') continue;
        else if(input[i] == ')'){
            char m1, m2;
            if(pila.size() > 1){
                matrix m2 = pila.top();
                pila.pop();
                matrix m1 = pila.top();
                pila.pop();
                if(m1.col == m2.row){
                    ans+=m1.col*m1.row*m2.col;
                    matrix newM;
                    newM.setValues(m1.name, m1.row, m2.col);
                    pila.push(newM);
                }else{
                    error = true;
                    break;
                }
            }
        }else{
            matrix newM;
            newM.setValues(input[i], matrixM[input[i]].first, matrixM[input[i]].second);
            pila.push(newM);
        }
    }
    if(pila.size() > 1) error = true;
    if(error) printf("error\n");
    else printf("%d\n", ans);
}

int main(){
    char input[200];
    int n, row, col;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", input, &row, &col);
        matrixM[input[0]] = make_pair(row, col);
    }
    while(scanf("%s", input)!=EOF){
        solve(input);
    }
    return 0;
}