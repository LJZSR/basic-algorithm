#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;
const int INF = 1000000;


int dist[MAX_N];
int dist2[MAX_N];
bool used[MAX_N];

int G[MAX_N][MAX_N];

int N, R;

void solve() {
  for (int i = 0; i < N; ++i) {
    dist[i] = INF;
    dist2[i] = INF;
    used[i] = false;
  }
  dist[0] = 0;
  while (true)
  {
    int k = -1;
    for (int i = 0; i < N; ++i) {
      if (!used[i] && (k == -1 || dist[i] < dist[k])) k = i;
    }
    if (k == -1) break;
    used[k] = true;
    for (int i = 0; i < N; ++i) {
      dist[i] = min(dist[i], dist[k] + G[k][i]);
    }
  }
  for (int i = 0; i < N; ++i) {
    dist2[0] = min(dist2[0], 2 * G[0][i]);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dist[i] == dist[j] + G[j][i]) {
        dist2[i] = min(dist2[i], dist2[j] + G[j][i]);
      }
      else {
        dist2[i] = min(dist2[i], dist[j] + G[i][j]);
      }
    }
  }
}

int main() {
  cin >> N >> R;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      G[i][j] = INF;
    }
  }
  for (int i = 0; i < R; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    G[s][t] = c;
    G[t][s] = c;
  }
  solve();
  for (int i = 0; i < N; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < N; ++i) {
    cout << dist2[i] << " ";
  }
  cout << endl;
  
  return 0;
}