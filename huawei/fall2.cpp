#include<iostream>
#include<vector>
#include<string>

using namespace std;

int M, N;
vector<vector<char> > graph;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

void dfs(int i, int j) {
  graph[i][j] = 'H';
  for (int index = 0; index < 4; ++index) {
    int x = i + dy[index];
    int y = j + dx[index];
    if (x >= 0 && x < M && y >= 0 && y < N && graph[x][y] == 'S') {
      dfs(x, y);
    }
  }
}

int solve() {
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (graph[i][j] == 'S') {
        dfs(i, j);
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  cin >> M;
  getchar();
  cin >> N;
  getchar();
  for (int i = 0; i < M; ++i) {
    string tmpstr;
    getline(cin, tmpstr);
    vector<char> row;
    for (int j = 0; j < N; ++j) {
      row.push_back(tmpstr[j]);
    }
    graph.push_back(row);
  }
  int ans = solve();
  cout << ans << endl;
}