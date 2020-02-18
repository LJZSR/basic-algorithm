#include <iostream>
#include <queue>

using namespace std;

const int INF = 100000;
const int MAX_V = 1000;

//first 最短距离; second 顶点号s
typedef pair<int, int> P;
struct edge
{
  int to, cost;
};

vector<edge> G[MAX_V];
int dist[MAX_V];
int V, E, S;

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  for (int i = 0; i < V; ++i) {
    dist[i] = INF;
  }
  dist[s] = 0;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    edge e;
    e.to = t;
    e.cost = c;
    G[s].push_back(e);
    e.to = s;
    G[t].push_back(e);
  }
  cin >> S;
  dijkstra(S);
  for (int i = 0; i < V; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
}