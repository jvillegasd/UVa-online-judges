#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

struct team{  //Usar struct para contener los datos
    int points, games, wins, ties, loses, GD, GS, GA;
    string name;
    char cmpName[40]; //Para poder comparar lexicograficamente
    void init(){
      points = 0; games = 0; wins = 0; ties = 0; loses = 0; GD = 0; GS = 0; GA = 0;
      name = "";;
    }
    void game(int goals1, int goals2){
        if(goals1 > goals2){
            wins++;
            points += 3;
        }else if(goals2 > goals1) loses++;
        else{
            ties++;
            points++;
        }
        games++;
        GS += goals1;
        GA += goals2;
        GD = GS - GA;
    }
};

void toLower(char cmps[40], string word){
    for(int i = 0; i < word.size(); i++){
        cmps[i] = tolower(word[i]);
    }
}

bool cmp(struct team team1, struct team team2) { //Usar un custom comparator para cumplir con el ejercicio
    if(team1.points != team2.points) return team1.points > team2.points;
    if(team1.wins != team2.wins) return team1.wins > team2.wins;
    if(team1.GD != team2.GD) return team1.GD > team2.GD;
    if(team1.GS != team2.GS) return team1.GS > team2.GS;
    if(team1.games != team2.games) return team1.games < team2.games;
    return strcmp(team1.cmpName, team2.cmpName) < 0;
}

int find(team arr[31], int size, string teamS){
    for(int i = 0; i < size; i++){
        if(strcmp(arr[i].name.c_str(),teamS.c_str())==0) return i;
    }
    return -1;
}

int main(){
    int N, T, G, goals1, goals2, cont = 0;
    string tournamentName, game, team1, team2, line;
    cin >> N;
    getline(cin, tournamentName); //Get new line
    while(cont < N){
        team teams[32];
        getline(cin, tournamentName);
        printf("%s\n", tournamentName.c_str());
        cin >> T;
        getline(cin, tournamentName); //Get new line
        for(int i = 0; i < T; i++){
          teams[i].init();
          getline(cin, teams[i].name);
          toLower(teams[i].cmpName, teams[i].name);
        }
        cin >> G;
        getline(cin, game); //Get new line    
        for(int i = 0; i < G; i++){
            getline(cin, game);
            bool hashF = false;
            team1 = "";
            team2 = "";
            goals1 = 0;
            goals2 = 0;
            int index = 0;
            for(index = 0; game[index] != '@'; index++){ //Concatenar caracter a caracter para solucionar errores
                if(game[index] == '#'){
                    hashF = true;
                    continue;
                }
                if(!hashF) team1 += game[index];
                else if(isdigit(game[index])) goals1 = goals1*10 + (game[index] - '0');
            }
            hashF = false;
            for(int j = index + 1; game[j] != '\0'; j++){
                if(game[j] == '#'){
                    hashF = true;
                    continue;
                }
                if(hashF) team2 += game[j];
                else if(isdigit(game[j])) goals2 = goals2*10 + (game[j] - '0');
            }
            int iTeam1 = find(teams, T, team1);
            int iTeam2 = find(teams, T, team2);
            teams[iTeam1].game(goals1, goals2);
            teams[iTeam2].game(goals2, goals1);
        }
        sort(teams, teams+T, cmp);
        for (int i = 0; i < T; i++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   (i + 1), teams[i].name.c_str(), teams[i].points, teams[i].games,
                   teams[i].wins, teams[i].ties, teams[i].loses, teams[i].GD,
                   teams[i].GS, teams[i].GA);
        if (cont != N - 1)
            printf("\n");
        cont++;
    }
}