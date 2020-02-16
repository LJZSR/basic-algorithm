#include <iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_K = 100000;

int n = 0;
int a[MAX_N], m[MAX_N];
int K = 0;

bool dp1[MAX_N][MAX_K+1];
int dp2[MAX_N][MAX_K+1];

bool solve1() {
  for (int j = 0; j <= K; ++j) {
    if (j % a[0] == 0 && j / a[0] <= m[0]) dp1[0][j] = true;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
        dp1[i][j] = dp1[i][j] || dp1[i-1][j-k*a[i]];
      }
    }
  }
  return dp1[n-1][K];
}

bool solve2() {
  for (int j = 0; j <= K; ++j) {
    if (j % a[0] == 0 && j / a[0] <= m[0]) dp2[0][j] = m[0] - j / a[0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      if (dp2[i-1][j] >= 0) {
        dp2[i][j] = m[i];
      }
      else {
        if (j >= a[i] && dp2[i][j-a[i]] >= 1) {
          dp2[i][j] = dp2[i][j-a[i]] - 1;
        }
        else {
          dp2[i][j] = -1;
        }
      }
    }
  }
  return dp2[n-1][K] >= 0;
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
      dp1[i][j] = false;
    }
  }
  for (int i = 0; i < MAX_N; ++i) {
    for (int j = 0; j <= MAX_K; ++j) {
      dp2[i][j] = -1;
    }
  }
  // bool ans = solve1();
  bool ans = solve2();
  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}