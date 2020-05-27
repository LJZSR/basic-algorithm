#include <iostream>
#include <vector>

using namespace std;

int N, K;
const int MAX_N = 100, MAX_K = 100;
const int MAX_V = MAX_N+MAX_K+2;
const int INF = 10000;

bool can[MAX_N][MAX_K];
bool used[MAX_V];

vector<edge> G[MAX_V];

struct edge
{
  /* data */
  int to, cap, rev;
};


void add_edge(int from, int to, int cap) {
  G[from].push_back(edge{to, cap, G[to].size()});
  G[to].push_back(edge{from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f) {
  if (v == t) return f;
  for (int i = 0; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap>0) {
      int d = dfs(e.to, t, min(e.cap, f));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
}

int max_flow(int s, int t) {
  int flow = 0;
  if (s == t) return flow;
  while (true) {
    for (int i = 0; i < MAX_V; ++i) {
      used[i] = false;
    }
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

void solve() {
  int s = N+K;
  int t = s+1;
  for (int i = 0; i < N; ++i) {
    add_edge(s, i, 1);
  }
  for (int i = 0; i < K; ++i) {
    add_edge(N+i, t, 1);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (can[i][j]) {
        add_edge(i, N+j, 1);
      }
    }
  }
  int ans = max_flow(s, t);
}
