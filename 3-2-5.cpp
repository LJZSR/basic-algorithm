#include <iostream>

using namespace std;

const int MAX_W = 1000000;
const int MAX_H = 1000000;
const int MAX_N = 500;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX_W][MAX_H];

int x1[MAX_N], x2[MAX_N], y1[MAX_N], y2[MAX_N];
int w, h, n;

void dfs(int x, int y) {
  map[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int cx = x + dx[i];
    int cy = y + dy[i];
    if (cx >= 0 && cx < w && cy >= 0 && cy < h && map[cx][cy] == 0) {
      dfs(cx, cy);
    }
  }
}

int solve1() {
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      map[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (x1[i] == x2[i]) {
      int begin = y1[i] < y2[i] ? y1[i] : y2[i];
      int end = y1[i] > y2[i] ? y1[i] : y2[i];
      for (int j = begin; j <= end; ++j) {
        map[x1[i]][j] = 1;
      }
    }
    else {
      int begin = x1[i] < x2[i] ? x1[i] : x2[i];
      int end = x1[i] > x2[i] ? x1[i] : x2[i];
      for (int j = begin; j <= end; ++j) {
        map[j][y1[i]] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (map[i][j] == 0) {
        dfs(i, j);
        ++ans;
      }
    }
  }
  return ans;
}

int main() {
  cin >> w >> h >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x1[i];
    x1[i]--;
  }
  for (int i = 0; i < n; ++i) {
    cin >> x2[i];
    x2[i]--;
  }
  for (int i = 0; i < n; ++i) {
    cin >> y1[i];
    y1[i]--;
  }
  for (int i = 0; i < n; ++i) {
    cin >> y2[i];
    y2[i]--;
  }
  int ans = solve1();
  cout << ans << endl;
  return 0;
}