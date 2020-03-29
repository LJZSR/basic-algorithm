#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 15;
const int MAX_M = 15;

int dp[2][1 << MAX_M];
bool color[MAX_N][MAX_M];
int n, m;

int solve() {
  int *crt = dp[0], *next = dp[1];
  crt[0] = 1;
  for (int i = n-1; i >= 0; --i) { 
    for (int j = m-1; j >= 0; --j) {
      for (int used = 0; used < (1 << m); ++used) {
        if (used >> j & 1 || color[i][j]) {
          next[used] = crt[used & ~(1 << j)];
        } 
        else
        {
          int res = 0;
          if (j+1 < m && !(used >> (j+1) & 1) && !color[i][j]) {
            res += crt[used | 1 << (j+1)];
          }
          if (i+1 < n && !color[i+1][j]) {
            res += crt[used | 1 << j];
          }
          next[used] = res;
        }
      }
      swap(crt, next);
    }
  }
  return crt[0];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == 'x') {
        color[i][j] = true;
      }
      else
      {
        color[i][j] = false;
      }
    }
  }
  int ans = solve();
  cout << ans << endl;
  return 0;

}