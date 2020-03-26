#include <iostream>

using namespace std;

const int MAX_M = 15;
const int MAX_N = 15;

int n, m;
bool color[MAX_N][MAX_M];
bool used[MAX_N][MAX_M];

int rec(int i, int j, bool color[MAX_N][MAX_M]) {
  if (j == m) {
    return rec(i+1, 0, color);
  }
  if (i == n) {
    return 1;
  }
  if (color[i][j]) {
    return rec(i, j+1, color);
  }
  color[i][j] = true;
  int ans = 0;
  if (j+1 < m && !color[i][j+1]) {
    color[i][j+1] = true;
    ans += rec(i, j+1, color);
    color[i][j+1] = false;
  }
  if (i+1 < n && !color[i+1][j]) {
    color[i+1][j] = true;
    ans += rec(i, j+1, color);
    color[i+1][j] = false;
  }
  color[i][j] = false;
  return ans;
}

int solve() {
  int ans = rec(0, 0, color);
  return ans;
}

int main() {
  cin >> n >> m;
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ch;
      if (ch == '.') {
        color[i][j] = false;
      }
      else
      {
        color[i][j] = true;
      }
    }
  }

  int ans = solve();
  cout << ans << endl;
}
