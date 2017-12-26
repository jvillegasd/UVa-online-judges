#include <stdio.h>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const tuple<string, int, int, int>& t1, const tuple<string, int, int, int>& t2){
    if(get<3>(t1) > get<3>(t2)) return true;
    else if(get<3>(t1)==get<3>(t2) && get<2>(t1) > get<2>(t2)) return true;
    else if(get<3>(t1)==get<3>(t2) && get<2>(t1)==get<2>(t2) && get<1>(t1) > get<1>(t2)) return true;
    return false;
}

int main(){
    int n, day, month, year;
    string name;
    char junk[20];
    vector<tuple<string, int, int ,int>> bornDate;
    scanf("%d", &n);
    while(n--){
        scanf("%s %d %d %d", &junk, &day, &month, &year);
        name = junk;
        bornDate.push_back(tuple<string, int, int, int>(name, day, month, year));
    }
    sort(bornDate.begin(), bornDate.end(), cmp);
    cout << get<0>(bornDate[0]) << endl;
    cout << get<0>(bornDate[bornDate.size() - 1]) << endl;
    return 0;
}
/*
    La estrategia a usar es un tuple y crear un metodo custom para ordenar el vector donde tengo las fechas de
    nacimiento. Aprendizaje: Gracias a este problema pude aprender algo nuevo de C++ que son los tuple.
*/