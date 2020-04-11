#include <iostream>

using namespace std;

const int MAX_N = 3000;

char G[MAX_N][MAX_N];
int x, y, n;

int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int x, int y) {
  if (G[x][y] == '.') {
    G[x][y] = '#';
  }
  else {
    ans += G[x][y] - '0';
    G[x][y] = '#';
  }
  for (int i = 0; i < 4; ++i) {
    int cx = x + dx[i];
    int cy = y + dy[i];
    if (cx >= 0 && cx < n && cy >= 0 && cy < n && G[cx][cy] != '#') {
      solve(cx, cy);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> G[i][j];
    }
  }
  cin >> x >> y;
  solve(x, y);
  cout << ans << endl;
  return 0;
}