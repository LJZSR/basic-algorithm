#include<iostream>
#include<string>
#include<vector>

using namespace std;

int T;
int m, n;
const int MAX_N = 100, MAX_M = 100;
char G[MAX_N][MAX_M];

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

bool dfs(int i, int j) {
  bool ans = false;
  if (G[i][j] == 'E') {
    return true;
  }
  G[i][j] = '#';
  for (int index = 0; index < 4; ++index) {
    int x = i + dy[index];
    int y = j + dx[index];
    if (x >= 0 && x < n && y >= 0 && y < m && (G[x][y] == '.' || G[x][y] == 'E')) {
      ans = dfs(x, y);
    }
  }
  return ans;
}

bool solve(int n, int m) {
  bool ans = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (G[i][j] == 'S') {
        ans = dfs(i,j);
        break;
      }
    }
  }
  return ans;
}

int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> n >> m;
    getchar();
    for (int j = 0; j < n; ++j) {
      string str;
      getline(cin, str);
      for (int k = 0; k < m; ++k) {
        G[j][k] = str[k];
      }
    }
    bool ans = solve(n, m);
    if (ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}