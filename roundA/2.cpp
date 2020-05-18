#include <iostream>
#include <algorithm>


using namespace std;
const int MAX_N = 50;
const int MAX_K = 30;
int value[MAX_N][MAX_K+1];
int dp[MAX_N][MAX_N*MAX_K];

int T;
int N, K, P;
int solve(int n, int p) {
  if (dp[n][p] >= 0) return dp[n][p];
  int ans = 0;
  int end = min(p, K);
  if (n == 0) {
    if (p <= K) return value[0][p];
  }
  for (int i = 0; i <= end; ++i) {
    if (p - i <= n * K) {
      ans = max(ans, value[n][i] + solve(n-1, p-i));
    }
  }
  dp[n][p] = ans;
  return ans;
}
int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N >> K >> P;
    for (int j = 0; j < N; ++j) {
      value[j][0] = 0;
      for (int k = 1; k <= K; ++k) {
        int c;
        cin >> c;
        value[j][k] = value[j][k-1] + c;
      }
    }
    for (int m = 0; m < MAX_N; ++m) {
        for (int n = 0; n < MAX_N*MAX_K; ++n) {
            dp[m][n] = -1;
        }
    }
    int ans = solve(N-1, P);
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
}
