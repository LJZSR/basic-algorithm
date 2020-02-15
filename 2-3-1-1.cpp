#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_W = 1000;
int n;
int W;
int w[MAX_N], v[MAX_N];
int ans;
int dp[MAX_N+1][MAX_W+1];

int solve1(int i, int j) {
  //深度搜索
  int ans;
  if (i == n) ans = 0;
  else {
    if (j < w[i]) {
      ans =  solve1(i+1, j);
    }
    else {
      ans = max(solve1(i+1, j), v[i] + solve1(i+1, j-w[i]));
    }
  }
  return ans;
}

int solve2(int i, int j) {
  //记忆化搜索
  if (dp[i][j] >= 0) {
    return dp[i][j];
  }
  int ans = 0;
  if (i == n) {
    ans = 0;
  }
  else {
    if (j < w[i]) {
      ans = solve2(i+1, j);
    }
    else {
      ans = max(solve2(i+1, j), v[i] + solve2(i+1, j-w[i]));
    }
  }
  dp[i][j] = ans;
  return ans;
}

int solve3() {
  for (int i = n-1; i >=0; --i) {
    for (int j = 0; j <= W; ++j) {
      if (j < w[i]) {
        dp[i][j] = dp[i+1][j];
      }
      else {
        dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
      }
    }
  }
  return dp[0][W];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    cin >> v[i];
  }
  cin >> W;

  // 深度搜索
  // int ans = solve1(0, W);
  // cout << ans << endl;

  //记忆化搜索
  // for (int i = 0; i < MAX_N+1; ++i) {
  //   for (int j = 0; j < MAX_W+1; ++j) {
  //     dp[i][j] = -1;
  //   }
  // }
  // int ans = solve2(0, W);
  // cout << ans << endl;

  //dp
  for (int i = 0; i < MAX_N+1; ++i) {
    for (int j = 0; j < MAX_W+1; ++j) {
      dp[i][j] = 0;
    }
  }
  int ans = solve3();
  cout << ans << endl;
  return 0;
}