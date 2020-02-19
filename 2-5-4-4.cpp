#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1000;
const int INF = 1000000;

bool used[MAX_V];

vector<int> G[MAX_V];

int cost[MAX_V][MAX_V];
int dist[MAX_V];
int pre[MAX_V];

int V, E, S, T;

void dijkstra(int s) {
  for (int i = 0; i < V; ++i) {
    used[i] = false;
    dist[i] = INF;
    pre[i] = -1;
  }
  dist[s] = 0;
  while (true) {
    int k = -1;
    for (int i = 0; i < V; ++i) {
      if (!used[i] && (k==-1 || dist[i] < dist[k])) k = i;
    }
    if (k == -1) break;
    used[k] = true;

    for (int i = 0; i < G[k].size(); ++i) {
      int p = G[k][i];
      if (dist[p] > dist[k] + cost[k][p]) {
        dist[p] = dist[k] + cost[k][p];
        pre[p] = k;
      }
    }
  }
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
  cin >> S >> T;
  dijkstra(S);
  for (int i = 0; i < V; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < V; ++i) {
    cout << pre[i] << " ";
  }
  cout << endl;
  cout << dist[T] << endl;
  while (T != -1) {
    cout << T << " ";
    T = pre[T];
  }
  cout << endl;
  return 0;
}