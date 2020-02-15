#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
int n;
int W;
int w[MAX_N], v[MAX_N];
int ans;

int solve1(int i, int j) {
  //深度搜索
  int ans;
  if (i == n) ans = 0;
  else {
    if (j < w[i]) {
      ans =  solve1(i+1, j);
    }
    else {
      ans = max(solve1(i+1, j), v[i] + solve1(i+1, j-w[i]));
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    cin >> v[i];
  }
  cin >> W;
  int ans = solve1(0, W);
  cout << ans << endl;
  return 0;
}