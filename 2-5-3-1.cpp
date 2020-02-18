#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1000;

vector<int> G[MAX_V];
int V = 0, E = 0;
int color[MAX_V];

bool dfs(int v, int c) {
  color[v] = c;
  for (int i = 0; i < G[v].size(); ++i) {
    if (color[G[v][i]] == c) return false;
    else if (color[G[v][i]] == 0 && !dfs(G[v][i], -1*c)) return false;
  } 
  return true;
}

bool solve() {
  for (int i = 0; i < V; ++i) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  bool ans = solve();
  if (ans) cout << "Yes!" << endl;
  else cout << "No!" << endl;
  return 0;
}