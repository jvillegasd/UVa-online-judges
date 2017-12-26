#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

int main(){
    int t, n, teammate, team, cases = 0;
    char option[13];
    while(scanf("%d", &t) && t != 0){
        printf("Scenario #%d\n", cases + 1);
        map<int, int> teams;
        queue<int> teamQueue[1010];
        queue<int> teamLeader;
        for(int i = 0; i < t; i++){
            scanf("%d", &n);
            for(int j = 0; j < n; j++){
                scanf("%d", &teammate);
                teams[teammate] = i;
            }
        }
        while(scanf("%s", option) && strcmp(option, "STOP") != 0){
            if(strcmp(option, "ENQUEUE") == 0){
                scanf("%d", &teammate);
                team = teams[teammate];
                if(teamQueue[team].empty()) teamLeader.push(team);
                teamQueue[team].push(teammate); 
            }else if(strcmp(option, "DEQUEUE") == 0){
                team = teamLeader.front();
                printf("%d\n", teamQueue[team].front());
                teamQueue[team].pop();
                if(teamQueue[team].empty()) teamLeader.pop();
            }
        }
        cases++;
        printf("\n");
    }
    return 0;
}
/*
    La estrategia es usar 2 queue y un map, una queue que represente las primeras personas de teams diferentes que 
    llegaron, ellos serian los lideres y la otra para representar la queue de ese equipo (esta seria un vector de queue) 
    y el map para saber a que team pertenece cada persona. Tarde mucho para llegar a esta solucion ya que la primera 
    solucion trabajaba con un vector y una queue que practicamente realizaba lo mismo, ya que con el vector simulaba 
    una queue sin darme cuenta, demore tratando de optimizarlo pero tuve que cambiarlo debido a que UVA mandaba RTE.
*/