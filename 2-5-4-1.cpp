#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;
const int MAX_V = 1000;

vector<int> G[MAX_V];

int cost[MAX_V][MAX_V];
int dist[MAX_V];
bool used[MAX_V];
int V, E, S;

void dijkstra(int s) {
  for (int i = 0; i < V; ++i) {
    dist[i] = INF;
    used[i] = false;
  }
  dist[s] = 0;
  while (true) {
    int v = -1;
    for (int i = 0; i < V; ++i) {
      if (!used[i] && (v == -1 || dist[i] < dist[v])) v = i; 
    }
    if (v == -1) break;
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
      dist[G[v][i]] = min(dist[G[v][i]], dist[v] + cost[v][G[v][i]]); 
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
  cin >> S;
  
  dijkstra(S);
  for (int i = 0; i < V; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
}
