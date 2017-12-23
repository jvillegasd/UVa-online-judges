#include <iostream>
#include <queue>
#include <vector>

using namespace std;   //Kahn's algorithm for topological sort

int matrizA[100][100];
int inDegree[100];
vector<int> sortedG;

void topologicalSort(int n){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0) q.push(i); //Push into the queue all vertex with zero in-edges
	}
	while(!q.empty()){
		int vertex = q.front();
		sortedG.push_back(vertex); //Push all vertex with zero in-egdes to the sorted vector
		q.pop();
		for(int i = 1; i <= n; i++){
			inDegree[matrizA[vertex][i]] = inDegree[matrizA[vertex][i]] - 1; //Decrease by 1 adjacent inDegree[] edges
			if(inDegree[matrizA[vertex][i]] == 0){ //If equals zero push it into the queue
				q.push(i);
			}
		}
	}
}

void reset(int n){
  for(int i = 1; i<= n; i++){
      inDegree[i] = 0;
      for(int j = 1; j <= n; j++){
        matrizA[i][j] = 0;
      }
    }
}

int main(){
	int n, m, in, out;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		sortedG.clear();
		for(int i = 1; i <= m; i++){
			cin >> out >> in;
			matrizA[out][in] = in;
			inDegree[in] = inDegree[in] + 1; //Calculate in-edges of out-vertex
		}
		topologicalSort(n);
		for(int i = 0; i < n; i++){
			cout << sortedG[i] << " ";
		}
		cout<<endl;
		reset(n);
	}
	return 0;
}