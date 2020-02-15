#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_M = 1000;
const int MAX_N = 1000;

int m, n;

char s[MAX_M], t[MAX_N];
int dp[MAX_M][MAX_N];

int solve() {

  for (int i = 0; i < m; ++i) {
    if (s[i] == t[0]) dp[i][0] = 1;
    else dp[i][0] = 0;
  }
  for (int j = 0; j < n; ++j) {
    if (s[0] == t[j]) dp[0][j] = 1;
    else dp[0][j] = 0;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (s[i] == t[j]) {
        int tmp = max(dp[i-1][j], dp[i][j-1]);
        dp[i][j] = max(tmp, dp[i-1][j-1]+1);
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m-1][n-1];
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}