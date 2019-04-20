#include <stdio.h>
#include <string>

using namespace std;

char board[8][8] = {'*'};

void bPawn(int x, int y, bool ab[8][8]){
    if(y + 1 < 8){
        if(x - 1 >= 0) ab[y + 1][x - 1] = true;
        if(x + 1 < 8) ab[y + 1][x + 1] = true;
    }
}

void wPawn(int x, int y, bool ab[8][8]){
    if(y - 1 >= 0){
        if(x - 1 >= 0) ab[y - 1][x - 1] = true;
        if(x + 1 < 8) ab[y - 1][x + 1] = true;
    }
}

void knight(int x, int y, bool ab[8][8]){
    if(y + 2 < 8){
        if(x + 1 < 8) ab[y + 2][x + 1] = true;
        if(x - 1 >= 0) ab[y + 2][x - 1] = true;
    }
    if(y - 2 >= 0){
        if(x + 1 < 8) ab[y - 2][x + 1] = true;
        if(x - 1 >= 0) ab[y - 2][x - 1] = true;
    }
    if(x + 2 < 8){
        if(y + 1 < 8) ab[y + 1][x + 2] = true;
        if(y - 1 >= 0) ab[y - 1][x + 2] = true;
    }
    if(x - 2 >= 0){
        if(y + 1 < 8) ab[y + 1][x - 2] = true;
        if(y - 1 >= 0) ab[y - 1][x - 2] = true;
    }
}

void rock(int x, int y, bool ab[8][8]){
    for(int i = x + 1; i < 8; i++){
        if(board[y][i] != '*') break;
        ab[y][i] = true;
    }
    for(int i = x - 1; i >= 0; i--){
        if(board[y][i] != '*') break;
        ab[y][i] = true;
    }
    for(int i = y + 1; i < 8; i++){
        if(board[i][x] != '*') break;
        ab[i][x] = true;
    }
    for(int i = y - 1; i >= 0; i--){
        if(board[i][x] != '*') break;
        ab[i][x] = true;
    }
}

void alfil(int x, int y, bool ab[8][8]){
    for(int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--){
        if(board[j][i] != '*') break;
        ab[j][i] = true;
        
    }
    for(int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++){
        if(board[j][i] != '*') break;
        ab[j][i] = true;
        
    }
    for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
        if(board[j][i] != '*') break;
        ab[j][i] = true;
        
    }
    for(int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++){
        if(board[j][i] != '*') break;
        ab[j][i] = true;
        
    }
}

void king(int x, int y, bool ab[8][8]){
    if(y + 1 < 8){
        ab[y + 1][x] = true;
        if(x + 1 < 8) ab[y + 1][x + 1] = true;
        if(x - 1 >= 0) ab[y + 1][x - 1] = true;
    }
    if(y - 1 >= 0){
        ab[y - 1][x] = true;
        if(x + 1 < 8) ab[y - 1][x + 1] = true;
        if(x - 1 >= 0) ab[y - 1][x - 1] = true;
    }
    if(x + 1 < 8) ab[y][x + 1] = true;
    if(x - 1 >= 0) ab[y][x - 1] = true;
}

int main(){
    char input[100];
    while(scanf("%s", input) != EOF){
        int row = 0, col = 0, cont = 0;
        bool attackedBoard[8][8] = {false};
        for(int i = 0; input[i] > 0; i++){
            if(input[i] == '/'){
                row++;
                for(int j = 0; j < 8; j++) board[row][j] = '*';
                col = 0;
            }
            else if(input[i] >= '1' && input[i] <= '9'){
                for(int j = 0; j < input[i] - '0'; j++){
                    board[row][col] = '*'; 
                    col++;
                }
            }else if(isalpha(input[i])){
                board[row][col] = input[i];
                col++;
            }
        }
        bool sw = true;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == '*') continue;
                attackedBoard[i][j] = true;
                if(board[i][j] == 'P') wPawn(j, i, attackedBoard);
                else if(board[i][j] == 'p') bPawn(j, i, attackedBoard);
                else if(board[i][j] == 'n' || board[i][j] == 'N') knight(j, i, attackedBoard);
                else if(board[i][j] == 'r' || board[i][j] == 'R') rock(j, i, attackedBoard);
                else if(board[i][j] == 'b' || board[i][j] == 'B') alfil(j, i, attackedBoard);
                else if(board[i][j] == 'k' || board[i][j] == 'K') king(j, i, attackedBoard);
                else if(board[i][j] == 'q' || board[i][j] == 'Q'){
                    alfil(j, i, attackedBoard);
                    rock(j, i, attackedBoard); 
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++) if(!attackedBoard[i][j]) cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}