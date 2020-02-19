#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_V = 1000;
const int INF = 100000;

int dist[MAX_V][MAX_V];

int V, E;

void warshall_floyed() {
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
}
int main() {
  cin >> V >> E;
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      }
      else {
        dist[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < E; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    dist[s][t] = c;
    dist[t][s] = c;
  }
  warshall_floyed();
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}