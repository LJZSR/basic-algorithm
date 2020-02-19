#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 1000;
const int INF = 1000000;

vector<int> G[MAX_V];
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];

int V, E;

int prim() {
  int ans = 0;
  used[0] = true;
  mincost[0] = 0;
  for (int i = 0; i < V; ++i) {
    mincost[i] = cost[0][i];
  }
  while (true) {
    int k = -1;
    for (int i = 0; i < V; ++i) {
      if (!used[i] && (k == -1 || mincost[i] < mincost[k])) k = i;
    }
    if (k == -1) break;
    used[k] = true;
    ans += mincost[k];
    for (int i = 0; i < G[k].size(); ++i) {
      int p = G[k][i];
      mincost[p] = min(mincost[p], cost[k][p]);
    }
  }
  return ans;
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      cost[i][j] = INF;
    }
  }
  for (int i = 0; i < E; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    G[s].push_back(t);
    G[t].push_back(s);
    cost[s][t] = c;
    cost[t][s] = c;
  }
  int ans = prim();
  cout << ans << endl;
  return 0;
}