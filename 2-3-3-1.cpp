#include <iostream>

using namespace std;

const int MAX_M = 1000;
const int MAX_N = 1000;

int m = 0, n = 0, M = 0;

int dp[MAX_M+1][MAX_N+1];

int solve() { 
  for (int i = 0; i <= m; ++i) dp[i][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j >= i) {
        dp[i][j] = dp[i-1][j] + dp[i][j-i];
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[m][n] % M;
}

int main() {
  cin >> n;
  cin >> m;
  cin >> M;
  int ans = solve();
  cout << ans << endl;
  return 0;
}