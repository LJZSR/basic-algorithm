#include <iostream>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int M = 0, n = 0, m = 0;
int a[MAX_N];
int dp[MAX_N][MAX_M+1];

int solve() {
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 1;
  }
  for (int j = 0; j <= m; ++j) {
    if (a[0] >= j) dp[0][j] = 1;
    else dp[0][j] = 0;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] <= j-1) {
        dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i]];
      }
      else {
        dp[i][j] = dp[i][j-1] + dp[i-1][j];
      }
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return dp[n-1][m] % M;
}

int main() {
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> M;
  int ans = solve();
  cout << ans << endl;
  return 0; 
}