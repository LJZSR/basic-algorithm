#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100;
const int INF = 100000;

struct edge {
  int to;
  int cap;
  int rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f) {
  if (v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
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
  while (true) {
    for (int i = 0; i < MAX_V; ++i) {
      used[i] = false;
    } 
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    else {
      flow += f;
    }
  }
}