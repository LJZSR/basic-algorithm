#include <iostream>

using namespace std;

const int MAX_N = 1000;

int n = 0, a[MAX_N];

int dp[MAX_N];

int solve() {
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    int max = 0;
    for (int j = i-1; j >=0; --j) {
      if (a[j] < a[i]) {
        max = dp[j] > max ? dp[j] : max;
      }
    }
    dp[i] = max + 1;
  }
  int ans = dp[0];
  for (int i = 1; i < n; ++i) {
    ans = ans > dp[i] ? ans : dp[i];
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}