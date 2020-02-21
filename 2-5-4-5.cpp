#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1000;
const int INF = 1000000;

struct edge
{
  int u, v, cost;
};

int dist[MAX_V];
vector<edge> G;
int V, E;

void bellman_ford(int s) {
  for (int i = 0; i < V; ++i) dist[i] = INF;
  dist[s] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < E; ++i) {
      edge e = G[i];
      if (dist[e.v] > dist[e.u] + e.cost) {
        dist[e.v] = dist[e.u] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edge e;
    e.u = u;
    e.v = v;
    e.cost = c;
    G.push_back(e);
    e.u = v;
    e.v = u;
    e.cost = c;
    G.push_back(e);
  }
  E *= 2;
  bellman_ford(0);
  for (int i = 0; i < V; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
} 