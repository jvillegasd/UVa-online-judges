#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int numF, maxC, spaces, index, C, cAux;
    double minF;
    string file, maxS, line = "------------------------------------------------------------";
    vector<string> files;
    while(true){
        cin >> numF;
        if(cin.fail())break;
        getline(cin, file); //Get new line
        maxS = "";
        maxC = 1;
        minF = 0;
        C = 0;
        index = 0;
        files.clear();
        for(int i = 0; i < numF; i++) {
            cin >> file;
            files.push_back(file);
            if(file.size() > maxS.size()) maxS = file;
        }
        sort(files.begin(), files.end());
        C = maxS.size();
        spaces = C + 2;
        cAux = C + 2;
        while(C + cAux <= 60){
            C += cAux;
            maxC++;
        }
        minF = ceil((double)numF/maxC);
        cout << line << endl;
        for(int i = 0; i < minF; i++){
            for(int j = 0; j < maxC; j++){
                if(index + j*minF >= files.size()) break;
                printf("%s",files.at(index + j*minF).c_str());
                string word = files.at(index + j*minF).c_str();
                int deltaSpaces = word.size() - spaces;
                deltaSpaces = abs(deltaSpaces);
                printf("%*s", deltaSpaces, "");
            }
            index++;
            printf("\n");
        }
    }
    return 0;
}