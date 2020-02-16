#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_V = 100;
const int INF = 100000000;

int n = 0;
int W = 0;
int w[MAX_N];
int v[MAX_N];

int dp[MAX_N+1][MAX_N*MAX_V+1];
int sum = 0;


int solve() {
  for (int j = 0; j < sum; ++j) {
    if (v[0] == j) dp[0][j] = w[0];
  }
  for (int i = 1; i < n; ++i) {
    for  (int j = 0; j <= sum; ++j) {
      if (j < v[i]) dp[i][j] = dp[i-1][j];
      else {
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (dp[i][j] <= W && ans < j) {
        ans = j;
      } 
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    cin >> v[i];
    sum += v[i];
  }
  cin >> W;
  for (int i = 0; i < MAX_N + 1; ++i) {
    for (int j = 0; j < MAX_N*MAX_V+1; ++j) {
      dp[i][j] = INF;
    }
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}