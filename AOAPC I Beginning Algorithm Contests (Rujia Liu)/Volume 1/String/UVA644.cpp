#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> binary;
    char line[20];
    bool prefix;
    int set = 0;
    while(scanf("%s", &line) != EOF){
        if(strcmp(line, "9") != 0) binary.push_back(line);
        else{
            set++;
            prefix = false;
            sort(binary.begin(), binary.end());
            for(int i = 0; i < binary.size() && !prefix; i++){
                for(int j = i + 1; j < binary.size(); j++){
                    if(binary[j].find(binary[i]) == 0){
                        prefix = true;
                        break;
                    }
                }
            }
            if(prefix) printf("Set %d is not immediately decodable\n", set);
            else printf("Set %d is immediately decodable\n", set);
            binary.clear();
        }
    }
}