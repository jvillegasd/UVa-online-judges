#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<pair<int, double>> digraph[105];
bool recStack[105];
double dist[105];
long long total; 
int n, m;

bool DFS(int u, double avg){
  recStack[u] = true;
  for(pair<int, double> p : digraph[u]){
    int v = p.first;
    double w = p.second;
    if(dist[v] > dist[u] + w - avg){
      dist[v] = dist[u] + w - avg;
      if(recStack[v] || DFS(v, avg)) return true;
    }
  }
  recStack[u] = false;
  return false;
}

bool negativeCycle(double avg){
  memset(dist, 0, n);
  memset(recStack, false, sizeof(recStack));
  for(int i = 1; i <= n; i++) if(DFS(i, avg)) return true;
  return false;
}

void binarySearch(){
  double l = 0, r = total + 1, mid;
  while(r - l > 1e-3){
    mid = (l + r)/2.0;
    if(negativeCycle(mid)) r = mid;
    else l = mid;
  }
  if(negativeCycle(r)) printf("%.2lf\n", l);
  else printf("No cycle found.\n");
}

int main() {
  int tc, count = 1, a, b, c;
  double minAvg;
  scanf("%d", &tc);
  while(count <= tc){
    total = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) digraph[i].clear();
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        digraph[a].push_back(make_pair(b, c));
        total+=c;
    }
    printf("Case #%d: ", count);
    binarySearch();
    count++; 
  }
  return 0;
}
/*
  La idea principal es buscar el ciclo con menor promedio de peso. Por mi parte opté por usar DFS para poder
  buscar los ciclos y por esto, se me ocurrió primero obtener los SCC del digrafo, luego, ir en cada componente
  y comparando los promedios de los ciclos pero esto no funcionó del todo. Para poder hallar la respuesta tuve
  que analizar demasiado el texto y enfatizar en "Hallar el minimo promedio del peso de un ciclo" y aqui empezé a 
  descubrir como resolver este problema. Se sabe que la formula de promedio del peso de un ciclo es:
                                      Avg = (w1 + w2 + w3 + ... + wx)/x (1)
                                      Donde x = # de aristas del ciclo
  Entonces, al analizar lo que estaba haciendo con las SCC -comparar promedios con otros- y plasmarlo en (1), se
  crea la siguiente inecuación:
                                      Avg > (w1 + w2 + w3 + ... + wx)/x
                                      x*Avg > w1 + w2 + w3 + ... + wx
                                      0 > (w1 - Avg) + (w2 - Avg) + (w3 - Avg) + ... + (wx - Avg)
               Donde Avg es un promedio hallado anteriormente y el otro lado es el Avg del ciclo actual
  De esto se toma en cuenta de que el problema se resume en encontrar ciclos negativos que genere un Avg y aqui 
  uso busqueda binaria, para buscar esos Avg que me genere ciclos negativos y escoger el menor.
*/