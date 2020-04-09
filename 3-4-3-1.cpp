#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_M = 500000;
const int MAX_N = 50000;
const int INF = MAX_M+1;
int s[MAX_M], t[MAX_M];
int n, m;

int dp[MAX_M][MAX_N];

int solve() {
  if (s[0] == 0) {
    for (int j = 0; j < n; ++j) {
      if (j == t[0]) {
        dp[0][j] = 1;
      }
      else {
        dp[0][j] = INF;
      }
    }
  }
  else {
    dp[0][0] = 0;
    for (int j = 1; j < n; ++j) { 
      dp[0][j] = INF;
    }
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (t[i] != j) {
        dp[i][j] = dp[i-1][j];
      }
      else {
        dp[i][j] = dp[i-1][j];
        for (int k = j; k >= s[i]; --k) {
          dp[i][j] = min(dp[i][j], dp[i-1][k]+1);
        }
      }
    }
  }
  return dp[m-1][n-1];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s[i] >> t[i];
    --s[i];
    --t[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}