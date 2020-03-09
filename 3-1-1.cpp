#include <iostream>

using namespace std;

const int MAX_N = 1000000;

int n, k;
int a[MAX_N];

int solve() {
  int first = 0;
  int last = n;
  while (last != first) {
    int mid = (first + last) / 2;
    if (a[mid] >= k) {
      last = mid;
    }
    else {
      first = mid+1;
    }
  }
  return last;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> k;
  int ans = solve();
  cout << ans << endl;
  return 0;
}
