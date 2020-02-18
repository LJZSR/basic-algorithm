#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1000;
vector<int> G[MAX_V];
int V = 0, E = 0;
int color[MAX_V];


void dfs(int v, int c) 
{
  color[v] = c;
  for (int i = 0; i < G[v].size(); ++i) {
    if (color[G[v][i]] == 0) {
      int point = G[v][i];
      int flag[V + 1];
      for (int j = 0; j <= V; ++j) {
        flag[j] = 0;
      }
      for (int j = 0; j < G[point].size(); ++j) {
        if (color[G[point][j]] != 0) {
          flag[color[G[point][j]]] = 1;
        }
      }
      for (int j = 1; j <= V; ++j) {
        if (flag[j] == 0) {
          dfs(point, j);
          break;
        }
      }
    }
  }
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  int ans = 0;
  for (int i = 0; i < V; ++i) {
    if (color[i] == 0) {
      dfs(i, 1);
    }
  }
  for (int i = 0; i < V; ++i) {
    ans = ans > color[i] ? ans : color[i];
  }
  cout << ans << endl;
  return 0;
}