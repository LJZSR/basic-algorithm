#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 8;
const int MAX_M = 30;
const int INF = 50000;

int n, m, e, a, b;
int t[MAX_N];
int d[MAX_M][MAX_M];
double dp[1 << MAX_N][MAX_M];

double calc(int S, int v) {
  if (dp[S][v] != INF) return dp[S][v];
  if (S == ((1 << n)-1)) return dp[S][v];
  double ans = INF;
  for (int i = 0; i < n; ++i) {
    if (((S >> i) & 1) == 0) {
      for (int u = 0; u < m; ++u) {
        if (d[u][v] > 0) {
          ans = min(ans, calc(S | (1 << i), u)+ ((double)d[u][v])/t[i]);
        }
      }
    }
  }
  dp[S][v] = ans;
  return ans;
}

void solve() {
  for (int i = 0; i < (1 << MAX_N); ++i) {
    for (int j = 0; j < MAX_M; ++j) {
      dp[i][j] = INF;
    }
  }
  dp[(1 << n)-1][a] = 0;
  double ans = INF;
  for (int S = 0; S < (1<<n); ++S) {
    ans = min(ans, calc(S, b));
  }
  if (ans == INF) {
    cout << "Impossible" << endl;
  }
  else
  {
    cout << ans << endl;
  }
}

int main() {
  cin >> m >> e;
  memset(d, -1, sizeof(d));
  for (int i = 0; i < e; ++i) {
    int begin, end, cost;
    cin >> begin >> end >> cost;
    d[begin][end] = cost;
    d[end][begin] = cost;
  }
  cin >> n >> a >> b;
  --a;
  --b;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  solve();
  return 0;
}

