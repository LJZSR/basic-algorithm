#include <iostream>

using namespace std;

const int MAX_N = 1000;
int X[MAX_N];
int N = 0;
int R = 0;

int solve() {
  int i = 0;
  int ans = 0;
  while (i < N) {
    int right = X[i] + R;
    int j = i + 1;
    while (j < N && X[j] <= right) ++j;
    i = j - 1;
    ++ans;
    right = X[i] + R;
    while (j < N && X[j] <= right) ++j;
    i = j;
  }
  return ans;
}

int main() {
  cin >> N;
  cin >> R;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}