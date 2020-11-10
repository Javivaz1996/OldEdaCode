#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

typedef pair<int, int> arco; //first->peso second->vector
typedef vector<vector<arco> > grafo;

int main(){
  int n, m;
  while(cin >> n >> m){
    arco aux;
    aux.first = -1;
    aux.second = -1;
    grafo g_p(n, vector<arco> (0, aux));
    int u, v, c;//u->de dónde v-> a dónde c->cuánto coste
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      arco aux;
      aux.first = c;
      aux.second = v;
      g_p[u].push_back(aux); 
    }
    int inicio, fin;
    cin >> inicio >> fin;
    //Aquí empieza
    //n ya lo tengo
    vector<int> d (n, numeric_limits<int>::max());//aquí estarán los pesos mínimos para llegar desde el inicio a n
    d[inicio] = 0;
    vector<int> p (n, -1);//desde dónde lo hemos visitado 
    vector<bool> vis(n, false);
    priority_queue<arco, vector<arco>, greater<arco> > q;
    q.push(arco(0, inicio));
    while(not q.empty()){
      int actual = q.top().second;
      q.pop();
      if (not vis[actual]){
	vis[actual] = true;
	for(unsigned int i = 0; i < g_p[actual].size(); ++i){
	  int v = g_p[actual][i].second;//vector al que va desde actual
	  int peso = g_p[actual][i].first;
	  if(d[v] > d[actual] + peso){
	    d[v] = d[actual] + peso;
	    p[v] = actual;
	    q.push(arco(d[v], v));
	  }
	  
	}
      }
    }
    if (d[fin] < numeric_limits<int>::max()) {
      stack<int> pila;
      while(fin != inicio){
	pila.push(fin);
	fin = p[fin];
      }
      pila.push(fin);
      bool primer = true;
      while(not pila.empty()) {
        if (primer) cout << pila.top();
        else cout << ' ' << pila.top();
        primer = false;
        pila.pop();
    }
    cout << endl;
    }
    else cout << "no path from " << inicio << " to " << fin << endl;
  }
}