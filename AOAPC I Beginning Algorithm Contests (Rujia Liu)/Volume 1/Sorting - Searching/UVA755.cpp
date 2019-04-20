#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    char dic[] = "22233344455566670778889990";
    char number[100], concat[100];
    string newLine;
    int N, no;
    cin >> N;
    getline(cin, newLine);
    while(N-- > 0){
        cin >> no;
        getline(cin, newLine);
        map<string, int> ans;
        for(int i = 0; i < no; i++){
            cin.getline(number,100);
            int index = 0;
            for(int j = 0; number[j] > 0; j++){
                if(number[j] >= '0' && number[j] <= '9'){
                    concat[index] = number[j];
                    index++;
                }else if(isalpha(number[j])){
                    concat[index] = dic[number[j] - 'A'];
                    index++;
                }
                if(index == 3){
                    concat[index] = '-';
                    index++;
                }
            }
            concat[index] = '\0';
            ans[concat] += 1;
        }      
        bool duplicate = false;
        for(auto iterator = ans.begin(); iterator != ans.end(); iterator++){
            if(iterator->second != 1){
                duplicate = true;
                cout << iterator->first << " " << iterator->second << endl;
            }
        }
        if(!duplicate) printf("No duplicates.\n");
        if(N != 0) printf("\n");   
    }
    return 0;
}