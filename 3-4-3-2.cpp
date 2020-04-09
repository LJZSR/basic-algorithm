#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50000;
const int MAX_M = 500000;
const int INF = MAX_M + 1;

int n, m;
int s[MAX_M], t[MAX_M];
int dp[MAX_N + 1];

int solve() {
  dp[1] = 0;
  for (int i = 2; i <= MAX_N; ++i) {
    dp[i] = INF;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = t[i]; j >= s[i]; --j) {
      dp[t[i]] = min(dp[t[i]], dp[j] + 1);
    }
  }
  return dp[n];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s[i] >> t[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}