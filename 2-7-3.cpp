#include <iostream>

using namespace std;

const int MAX_Q = 100;
const int MAX_P = 10000;

int P, Q;
int A[MAX_Q+2];
int dp[MAX_Q+2][MAX_Q+2];

int solve(int i, int j) {
  int ans = MAX_P;
  if (dp[i][j] >= 0) {
    ans = dp[i][j];
  }
  else {
    if (i + 1 == j) {
      ans = 0;
    }
    for (int k = i+1; k < j; ++k) {
      int tmp = solve(i, k) + solve(k, j) + A[j] - A[i] - 2;
      ans = ans < tmp ? ans : tmp;
    }
    dp[i][j] = ans;
  }
  return ans;
}

int main() {
  cin >> P >> Q;
  for (int i = 1; i <= Q; ++i) {
    cin >> A[i];
  }
  A[0] = 0;
  A[Q+1] = P + 1;
  for (int i = 0; i <= Q+1; ++i) {
    for (int j = 0; j <= Q+1; ++j)
    dp[i][j] = -1;
  }
  int ans = solve(0, Q+1);
  cout << ans << endl;
  return 0;
}