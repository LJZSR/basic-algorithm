#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000000;

int s[MAX_N], t[MAX_N];

int solve(int n, int select[]) {
  pair<int, int> tmp[n];
  for (int i = 0; i < n; ++i) {
    tmp[i].first = t[i];
    tmp[i].second = s[i];
  }
  sort(tmp, tmp + n);
  int T = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (tmp[i].second > T) {
      select[ans] = i;
      ans++;
      T = tmp[i].first;
    }
  }
  return ans;
}

int main() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int select[MAX_N];
  int ans = solve(n, select);
  cout << "Result: " << endl;
  cout << ans << endl;
  for (int i = 0; i < ans; ++i) {
    cout << select[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}