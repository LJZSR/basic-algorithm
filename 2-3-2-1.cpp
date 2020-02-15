#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N+1][MAX_W+1];

int solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (j < w[i-1]) {
        dp[i][j] = dp[i-1][j];
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-w[i-1]] + v[i]);
      }
    }
  }
  return dp[n][W];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    cin >> v[i];
  }
  cin >> W;
  int ans = solve();
  cout << ans << endl;
  return 0;
}