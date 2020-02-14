#include <iostream>
#include <queue>

using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;
const int INF = 10000;

char maze[MAX_M][MAX_N];
int d[MAX_M][MAX_N];

int startX = 0, startY = 0;
int endX = 0, endY = 0;

int bfs(int m, int n) {
  queue<pair<int, int> > q;
  int tmpX[4] = {-1, 0, 1, 0};
  int tmpY[4] = {0, -1, 0, 1};
  d[startX][startY] = 0;
  pair<int, int> currentP;
  currentP.first = startX;
  currentP.second = startY;
  q.push(currentP);
  while (!q.empty())
  {
    currentP = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      pair<int, int> tmpP;
      tmpP.first = currentP.first + tmpX[i];
      tmpP.second = currentP.second + tmpY[i];
      if (tmpP.first >= 0 && tmpP.first < m && tmpP.second >= 0 && tmpP.second < m && (maze[tmpP.first][tmpP.second] == '.' || maze[tmpP.first][tmpP.second] == 'G') && d[tmpP.first][tmpP.second] == INF) {
        d[tmpP.first][tmpP.second] = d[currentP.first][currentP.second] + 1;
        q.push(tmpP);
      }
    }
  }
  return d[endX][endY];
}

int main() {
  int m = 0, n = 0;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = INF; 
      cin >> maze[i][j];
      if (maze[i][j] == 'S') {
        startX = i;
        startY = j;
      }
      if (maze[i][j] == 'G')
      {
        endX = i;
        endY = j;
      }
    }
  }
  int ans = bfs(m, n);
  cout << ans << endl;
  return 0;
}