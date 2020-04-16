#include <iostream>
#include <string>

using namespace std;

const int M = 1000000007;

int dp[5000][5000];

string S, T;

int counter(string s, string t, int i, int j) {
  int result = 0;
  for (int b = 0; b <= j; ++b) {
    for (int k = 0; k <= i; ++k) {
      if (s[k] == t[b]) {
        int indexs = k;
        int indext = b;
        while (indexs <= i && indext <= j && s[indexs] == t[indext]) {
          ++indexs;
          ++indext;
        }
        if (indext == j) {
          ++result;
        }
      }
    }
  }
  return result;
}

int main() {
  cin >> S >> T;
  if (S[0] == T[0]) {
    dp[0][0] = 1;
  }
  for (int i = 1; i < S.length(); ++i) {
    if (S[i] == T[0]) {
      dp[i][0] = dp[i-1][0] + 1;
    }
    else {
      dp[i][0] = dp[i-1][0];
    }
  }
  for (int j = 1; j < T.length(); ++j) {
    dp[S.length() - 1][j] = dp[S.length() - 1][j-1] + counter(S, T, S.length() - 1, j);
  }
  cout << dp[S.length() - 1][T.length() - 1] << endl;
  return 0;
}