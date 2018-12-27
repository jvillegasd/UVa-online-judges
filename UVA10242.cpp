#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> pdd;

int main(){
    double ax, ay, bx, by, cx, cy, x[4], y[4];
    set<pdd> st;
    set<pdd>::iterator it;
    while(scanf("%lf %lf", &x[0], &y[0]) != EOF){
        for(int i = 1; i < 4; i++) scanf("%lf %lf", &x[i], &y[i]);
        st.clear();
        for(int i = 0; i < 4; i++){
            if(st.find({x[i], y[i]}) != st.end()){
                st.erase({x[i], y[i]});
                cx = x[i];
                cy = y[i];
            } else st.insert({x[i], y[i]});
        }
        it = st.begin();
        ax = it->first;
        ay = it->second;
        it++;
        bx = it->first;
        by = it->second;
        printf("%.3lf %.3lf\n", ax + bx - cx, ay + by - cy);
    }
    return 0;
}
/*
    La propiedad del paralelogramo es que sus diagonales son iguales, entonces, usamos la ley del paralelogramo para
    obtener las diagonales:
                                                x1 + x3 = x2 + x4
                                                y1 + y3 = y2 + y4
    Despejando los puntos del cuarto vertice, las ecuaciones quedan asi:
                                                x4 = x1 + x3 - x2
                                                y4 = y1 + y3 - y2
                                    Donde (x2, y2) es la coordenada repetida
    
*/