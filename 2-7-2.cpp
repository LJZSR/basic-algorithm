#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 40;

int Matrix[MAX_N][MAX_N];
int a[MAX_N];

int N;

int solve() {
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int pos = -1;
    for (int j = i; j < N; ++j) {
      if (a[j] <= i) {
        pos = j;
        break;
      }
    }
    for (int j = pos; j > i; --j) {
      swap(a[j],a[j-1]);
      ans++;
    }
  }
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int last = -1;
    for (int j = 0; j < N; ++j) {
      cin >> Matrix[i][j];
      if (Matrix[i][j] == 1) {
        last = j;
      }
    }
    a[i] = last;
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}

