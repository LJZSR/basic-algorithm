#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int n;
int V;
const int MAX_V = 20000;
vector<int> G[MAX_V];
set<int> tmp;
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


int main() {
  string str;
  getline(cin, str);
  getline(cin, str);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v;
    tmp.insert(u);
    tmp.insert(v);
    cin >> u >> v;
    add_edge(u, v);
  }
  V = tmp.size();
  int ans = bipartitte_matching();
  cout << ans << endl;
  return 0;
}