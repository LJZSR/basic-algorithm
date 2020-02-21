#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int INF = 1000000;

struct edge
{
  int u, v, cost;
};

int dist[MAX_N];
vector<edge> G;
int N, ML, DL;

bool find_negative_loop() {
  for (int i = 0; i < N; ++i) {
    dist[i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < G.size(); ++j) {
      edge e = G[j];
      if (dist[e.v] > dist[e.u] + e.cost) {
        dist[e.v] = dist[e.u] + e.cost;
        if (i == N - 1) {
          return true;
        }
      }
    }
  }
  return false;
}

int bellman_ford() {
  for (int i = 0; i < N; ++i) {
    dist[i] = INF;
  }
  dist[0] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < G.size(); ++i) {
      edge e = G[i];
      if (dist[e.v] > dist[e.u] + e.cost) {
        dist[e.v] = dist[e.u] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
  return dist[N-1];
}

int main() {
  cin >> N >> ML >> DL;
  for (int i = 0; i < N-1; ++i) {
    edge e;
    e.u = i + 1;
    e.v = i;
  }
  for (int i = 0; i < ML; ++i) {
    int AL, BL, DL;
    cin >> AL >> BL >> DL;
    edge e;
    e.u = AL - 1;
    e.v = BL - 1;
    e.cost = DL;
    G.push_back(e);
  }
  for (int i = 0; i < DL; ++i) {
    int AD, BD, DD;
    cin >> AD >> BD >> DD;
    edge e;
    e.u = BD - 1;
    e.v = AD - 1;
    e.cost = -1 * DD;
    G.push_back(e);
  }
  bool flag = find_negative_loop();
  if (flag) {
    cout << "-1" << endl;
  }
  else {
    int ans = bellman_ford();
    if (ans == INF) {
      cout << "-2" << endl;
    }
    else
    {
      cout << ans << endl;
    }
  }
  return 0;
}
