#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void aroundY(char *cube){
    char temp = cube[1];
    cube[1] = cube[2];
    cube[2] = cube[4];
    cube[4] = cube[3];
    cube[3] = temp;
}

void aroundX(char *cube){
    char temp = cube[0];
    cube[0] = cube[4];
    cube[4] = cube[5];
    cube[5] = cube[1];
    cube[1] = temp;
}

void aroundZ(char *cube){
    char temp = cube[0];
    cube[0] = cube[3];
    cube[3] = cube[5];
    cube[5] = cube[2];
    cube[2] = temp;
}

bool equals(char *cube1, char *cube2){
    for (int i = 0; i < 6; i++){
        if (cube1[i] != cube2[i]) return false;
    }
    return true;
}

bool rotate(char *cube1, char *cube2){
    for(int z = 0; z < 4; z++){
        for(int j = 0; j < 4; j++){
            if(equals(cube1, cube2)) return true;
            aroundY(cube2);
        }
        for(int i = 0; i < 4; i++){
            if(equals(cube1, cube2)) return true;
            aroundX(cube2);
        }
        aroundZ(cube2);
    }
    return false;
}

int main(){
    string input;
    while(getline(cin, input)){
        char cube1[6];
        char cube2[6];
        for(int i = 0; i < 12; i++){
            if(i < 6) cube1[i] = input[i];
            else cube2[i - 6] = input[i];
        }
        if(rotate(cube1, cube2)) printf("TRUE\n");
        else printf("FALSE\n");
    }
    return 0;
}