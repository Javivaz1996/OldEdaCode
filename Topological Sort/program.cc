#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef vector<int> vint;
typedef vector<vint> graf;

list<int> topological(graf& topo){
    int n = topo.size();
    vint ge (n); //graf entrada
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < topo[i].size(); ++j){
            ++ge[topo[i][j]]; //en la posición x tendré de cuntas operaciones depende x
        }
    }
    priority_queue<int, vint, greater<int> > q;
    for (int i = 0; i < n; ++i){
        if(ge[i] == 0) q.push(i);
    }

    list<int> L;
    while (not q.empty()) {
        int u = q.top(); q.pop();
        L.push_back(u);
        for (int v : topo[u]) {
            if (--ge[v] == 0) {
                q.push(v);
            } } }
    return L;
}


int main() {
    int n; //#vertices
    int m; //#precedencias
    while(cin >> n >> m) {
        graf topo(n);
        for (int i = 0; i < m; ++i) {
            int a, b; //a->b
            cin >> a >> b;
            topo[a].push_back(b);
        }
        list<int> L = topological(topo);
        bool primer = true;
        while (not L.empty()) {
            if (not primer) cout << ' ';
            cout << L.front();
            L.pop_front();
            primer = false;
        }
        cout << endl;
    }
}