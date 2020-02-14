#include<iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_M][MAX_N];

void dfs(int x, int y, int m, int n) {
  field[x][y] = '.';
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      int px = x + dx;
      int py = y + dy;
      if (px >= 0 && px < m && py >= 0 && py < n && field[px][py] == 'W') {
        dfs(px, py, m, n);
      }
    }
  }
}

int main() {
  int m=0, n=0;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> field[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (field[i][j] == 'W') {
        dfs(i, j, m, n);
        ans++;
      }
    }
  }
  cout << ans << endl;
}