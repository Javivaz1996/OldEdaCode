#include <iostream>
#include <vector>

using namespace std;

void zeroone (int n, int o, int i, vector<bool>& v) {
  if (n == 0 and o == 0){
    for (unsigned int j = 0; j < v.size(); ++j){
      cout << v[j];
      if (j != v.size()-1) cout << ' ';
      else cout << endl;
    }
  }
  else {
    if (n != 0 and o != 0) {
      v[i] = false;
      zeroone(n-1, o, i+1, v);
      v[i] = true;
      zeroone(n, o-1, i+1, v);
    }
    else if(n == 0){
      v[i] = true;
      zeroone(n, o-1, i+1, v);
    }
    else if(o == 0){
      v[i] = false;
      zeroone(n-1, o, i+1, v);
    }
  }
}

int main(){
  int n;
  cin >> n;
  int o;
  cin >> o;
  vector<bool> v (n);
  n -= o;
  int i = 0;
  zeroone(n, o, i, v);
}