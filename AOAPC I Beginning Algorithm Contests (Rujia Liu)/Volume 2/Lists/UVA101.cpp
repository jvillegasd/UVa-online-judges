#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int blocks[30][30], n, ai, aj, bi, bj;

void set(){
    ai = aj = bi = bj = -1;
    for(int i = 0; i < n; i++){
        blocks[i][0] = i;
        blocks[i][1] = -1;
    }
}

bool check(int a, int b){
    if(a == b) return false;
    for(int i = 0; i < n; i++){
        for(int j = 0; blocks[i][j] != -1; j++){
            if(a == blocks[i][j]){
                for(int k = 0; blocks[i][k] != -1; k++){
                    if(b == blocks[i][k]) return false;
                }
            }
        }
    }
    return true;
}

void find(int a, int b){
    for(int i = 0; i < n; i++){
        for(int j = 0; blocks[i][j] != -1; j++){
            if(a == blocks[i][j]){
                ai = i;
                aj = j;
            }else if(b == blocks[i][j]){
                bi = i;
                bj = j;
            }
        }
    }
}

void moveOnto(int a, int b){
    if(check(a, b)){
        find(a, b);
        for(int j = aj + 1; blocks[ai][j] != -1; j++){
            blocks[blocks[ai][j]][0] = blocks[ai][j];
            blocks[blocks[ai][j]][1] = -1;
        }
        for(int j = bj + 1; blocks[bi][j] != -1; j++){
            blocks[blocks[bi][j]][0] = blocks[bi][j];
            blocks[blocks[bi][j]][1] = -1;
        }
        blocks[ai][aj] = -1; 
        blocks[bi][bj + 1] = a;
        blocks[bi][bj + 2] = -1;
    }
}

void moveOver(int a, int b){
    if(check(a, b)){
        find(a, b);
        for(int j = aj + 1; blocks[ai][j] != -1; j++){
            blocks[blocks[ai][j]][0] = blocks[ai][j];
            blocks[blocks[ai][j]][1] = -1;
        } 
        while(blocks[bi][bj] != -1) bj++;
        blocks[ai][aj] = -1;
        blocks[bi][bj] = a;
        blocks[bi][bj + 1] = -1;
    }
}

void pileOnto(int a, int b){
    if(check(a, b)){
        find(a, b);
        for(int j = bj + 1; blocks[bi][j] != -1; j++){
            blocks[blocks[bi][j]][0] = blocks[bi][j];
            blocks[blocks[bi][j]][1] = -1;
        }
        for(int j = aj; blocks[ai][j] != -1; j++) blocks[bi][++bj] = blocks[ai][j];
        blocks[ai][aj] = -1;
        blocks[bi][bj + 1] = -1;
    }
}

void pileOver(int a, int b){
    if(check(a, b)){
        find(a, b);
        while(blocks[bi][bj] != -1) bj++;
        for(int j = aj; blocks[ai][j] != -1; j++) blocks[bi][bj++] = blocks[ai][j];
        blocks[ai][aj] = -1;
        blocks[bi][bj] = -1;
    }
}

int main(){
    int a, b;
    cin >> n;
    string move, dir;
    set();
    while(cin >> move && move[0] != 'q'){
      cin >> a >> dir >> b;
      if(move == "move"){
            if(dir == "onto") moveOnto(a, b);
            else moveOver(a, b);
        }else{
            if(dir == "onto") pileOnto(a, b);
            else pileOver(a, b);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        for(int j = 0; blocks[i][j] != -1; j++) printf(" %d", blocks[i][j]);
        printf("\n");
    }
    return 0;
}