#include <iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_K = 100000;

int n = 0;
int a[MAX_N], m[MAX_N];
int K = 0;

bool dp[MAX_N][MAX_K+1];

bool solve1() {
  for (int j = 0; j <= K; ++j) {
    if (j % a[0] == 0 && j / a[0] <= m[0]) dp[0][j] = true;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
        dp[i][j] = dp[i][j] || dp[i-1][j-k*a[i]];
      }
    }
  }
  return dp[n-1][K];
}


int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cin >> m[i];
  }
  cin >> K;
  for (int i = 0; i < MAX_N; ++i) {
    for (int j = 0; j <= MAX_K; ++j) {
      dp[i][j] = false;
    }
  }
  bool ans = solve1();
  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}