#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 100;
const int INF = 1000000;

struct edge {
  int u, v, cost;
};

int par[MAX_V];
int height[MAX_V];

vector<edge> G;
int V, E;

void init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    height[i] = 0;
  }
}
int find(int i) {
  if (par[i] == i) return i;
  else return par[i] = find(par[i]);
}

bool same(int i, int j) {
  return (find(i) == find(j));
}

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (height[i] < height[j]) {
    par[i] = j;
  }
  else {
    par[j] = i;
    if (height[i] == height[j]) height[i]++;
  }
}

int comp(edge e1, edge e2) {
  return e1.cost < e2.cost;
}

int kruskal() {
  init(V);
  sort(G.begin(), G.end(), comp);
  int ans = 0;
  for (int i = 0; i < G.size(); ++i) {
    if (!same(G[i].u, G[i].v)) {
      ans += G[i].cost;
      unite(G[i].u, G[i].v);
    }
  }
  return ans;
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    edge e;
    e.u = s;
    e.v = t;
    e.cost = c;
    G.push_back(e);
  }
  int ans = kruskal();
  cout << ans << endl;
  return 0;
}
