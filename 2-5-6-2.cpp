#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int MAX_R = 50000;
const int INF = 1000000;


int par[MAX_M + MAX_N];
int height[MAX_M + MAX_N];

struct edge
{
  int u, v, cost;
};

void init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    height[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

bool same(int x, int y) {
  return (find(x) == find(y));
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (height[x] < height[y]) {
    par[x] = y;
  }
  else {
    par[y] = x;
    if (height[x] == height[y]) {
      ++height[x];
    }
  }
}

vector<edge> G;

int N, M, R, V;

int cmp(edge e1, edge e2) {
  return e1.cost < e2.cost;
}

int kruskal() {
  int ans = 0;
  init(V);
  sort(G.begin(), G.end(), cmp);
  for (int i = 0; i < G.size(); ++i) {
    if (!same(G[i].u, G[i].v)) {
      ans += G[i].cost;
      unite(G[i].u, G[i].v);
    }
  }
  return ans;
}

int main() {
  cin >> N >> M >> R;
  V = N + M;
  for (int i = 0; i < R; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    edge e;
    e.u = y;
    e.v = x + N;
    e.cost = -1 * c;
    G.push_back(e);
  }
  int ans = kruskal();
  cout << 10000 * V + ans << endl;
  return 0;
}