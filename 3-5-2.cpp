#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 100;
const int INF = 10000;
int level[MAX_V];
int iter[MAX_V];

struct edge
{
  int to;
  int cap;
  int rev;
};

vector<edge> G[MAX_V];

void add_edge(int from, int to, int cap) {
  G[from].push_back((edge) {to, cap, G[to].size()});
  G[to].push_back((edge) {from, 0, G[from].size()-1});
}


void bfs(int s) {
  for (int i = 0; i < MAX_V; ++i) {
    level[i] = -1;
  }
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < G[v].size(); ++i) {
      edge &e = G[v][i];
      if (level[e.to] < 0 && e.cap > 0) {
        level[e.to] = level[v]+1;
        q.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0;
  while (true) {
    bfs(s);
    if (level[t] < 0) return flow;
    for (int i = 0; i < MAX_V; ++i) {
      iter[i] = 0;
    }
    int f;
    while ((f = dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
}