#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 16000;
const int MAX_N = 15;

int N, E;
int d[MAX_N][MAX_N];

int dp[1 << MAX_N][MAX_N];

int res(int S, int v) {
  if (dp[S][v] > 0) return dp[S][v];
  if (S == (1 << N) - 1 && v == 0) {
    dp[S][v] = 0;
    return 0;
  }
  int ans = INF;
  for (int i = 0; i < N; ++i) {
    if (((S >> i) & 1) != 1) {
      ans = min(ans, res((S | (1 << i)), i) + d[v][i]);
    }
  }
  dp[S][v] = ans;
  return ans;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int ans = res(0, 0);
  cout << ans << endl;
}

int main() {
  cin >> N >> E;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      d[i][j] = INF;
    }
  }
  for (int i = 0; i < E; ++i) {
    int begin;
    int end;
    int cost;
    cin >> begin >> end >> cost;
    d[begin][end] = cost;
  }
  solve();
  return 0;
}
