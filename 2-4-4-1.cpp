#include <iostream>

using namespace std;

const int MAX_N = 50000;
const int MAX_K = 100000;

int N = 0, K = 0;
int T[MAX_K], X[MAX_K], Y[MAX_K];

int par[MAX_N*3];
int height[MAX_N*3];

void init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    height[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (height[x] < height[y]) {
    par[x] = y;
  }
  else {
    par[y] = x;
    if (height[x] == height[y]) height[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int solve() {
  init(3*N);
  int ans = 0;
  for (int i = 0; i < K; ++i) {
    int t = T[i];
    int x = X[i] - 1;
    int y = Y[i] - 1;
    if (x < 0 || x >= N || y < 0 || y >= N) {
      ans++;
      cout << "第" << i+1 << "条信息，动物种类越界。" << endl;
      continue;
    }
    if (t == 1) {
      if (same(x, y+N) || same(x, y+2*N) || same(x+N, y) || same(x+N, y+2*N) || same(x+2*N, y) || same(x+2*N, y+N)) {
        ans++;
        cout << "第" << i+1 << "条信息错误。" << endl;
      }
      else {
        unite(x, y);
        unite(x+N, y+N);
        unite(x+2*N, y+2*N);
      }
    }
    else {
      if (same(x, y) || same(x, y+2*N) || same(x+N, y) || same(x+N, y+N) || same(x+2*N, y+N) || same(x+2*N, y+2*N)) {
        ans++;
        cout << "第" << i+1 << "条信息错误。" << endl;
      }
      else {
        unite(x, y+N);
        unite(x+N, y+2*N);
        unite(x+2*N, y);
      }
    }
  }
  return ans;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> T[i] >> X[i] >> Y[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}

