#include <iostream>
#include <vector>

using namespace std;

int V;
const int MAX_V = 100;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i], w = match[u];
    if (w < 0 || !used[w] && dfs(w)) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}


int bipartitte_matching() {
  int res = 0;
  for (int i = 0; i < MAX_V; ++i) {
    match[i] = -1;
  }
  for (int v = 0; v < V; ++v) {
    if (match[v] < 0) {
      for (int i = 0; i < MAX_V; ++i) {
        used[i] = false;
      }
      if (dfs(v)) {
        ++res;
      }
    }
  }
  return res;
}
