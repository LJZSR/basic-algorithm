#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_M = 15;

double dp[2][(1 << MAX_M) + 1];

int M;
double P, X;

double solve() {
  int n = (1 << M) + 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j< n; ++j) {
      dp[i][j] = 1;
    }
  }
  int pre = 0;
  int nex = 1;
  dp[0][0] = 0;
  for (int i = 1; i <= M; ++i) {
    int nex_n  = (1 << i) + 1;
    for (int j = 0; j < nex_n; ++j) {
      double t = 0;
      for (int l = 0, r = j; l <= r; ++l, --r) {
        t = max(t, P * dp[pre][r] + (1-P) * dp[pre][l]);
      }
      dp[nex][j] = t;
    }
    swap(pre, nex);
  }
  for (int i = 0; i < n; ++i) {
    cout << dp[pre][i] << " ";
  }
  cout << endl;
  double gap = 1000000 / (n-1);
  int index = X / gap;
  return dp[pre][index];
}

int main() {
  cin >> M >> P >> X;
  double ans = solve();
  cout << ans << endl;
  return 0;
}

