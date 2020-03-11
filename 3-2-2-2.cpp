#include <iostream>

using namespace std;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, 1, -1, 0, 0};
const int MAX_M = 15, MAX_N = 15;

int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N];
int flip[MAX_M][MAX_N];

// 查询（x，y）颜色
int get(int x, int y) {
  int c = tile[x][y];
  for (int i = 0; i < 5; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 >=0 && x2 < N && y2 >= 0 && y2 < M) {
      c += flip[x2][y2];
    }
  }
  return c % 2;
}

int cal() {
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (get(i-1, j) != 0) {
        flip[i][j] = 1;
      }
    }
  }
  for (int j = 0; j < N; ++j) {
    if (get(M-1, j) != 0) {
      return -1;
    }
  }

  int res = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      res += flip[i][j];
    }
  }
  return res;
}

void solve() {
  int ans = -1;
  for (int i = 0; i < 1 << N; ++i) {
    memset(flip, 0, sizeof(flip));
    for (int j = 0; j < N; ++j) {
      flip[0][N-j-1] = i >> j & 1;
    }
    int num = cal();
    if (num >= 0 && (ans < 0 || ans > num)) {
      ans = num;
      memcpy(opt, flip, sizeof(flip));
    }
  }
  if (ans < 0) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << opt[i][j] << " ";
      }
      cout << endl;
    }
  }
}

int main() {
  cin >> M >> N;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> tile[i][j];
    }
  }
  cout << endl;
  solve();
  return 0;
}
