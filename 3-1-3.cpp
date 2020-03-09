#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

int X[MAX_N];
int N, M;

bool judge(int c) {
  int gap = X[c] - X[0];
  int curP = X[c];
  int num = 2;
  for (int i = c+1; i < N; ++i) {
    if (X[i] - curP >= gap) {
      ++num;
      curP = X[i];
    }
  }
  return num >= M;
}

int solve() {
  sort(X, X + N);
  int lb = 0, ub = N;
  while (ub != lb) {
    int mid = (lb + ub) / 2;
    if (judge(mid)) {
      lb = mid;
    }
    else {
      ub = mid - 1;
    }
  }
  return X[ub] - X[0];
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }

  int ans = solve();
  cout << ans << endl;
  return 0;
}