#include <iostream>

using namespace std;

typedef long long ll;
const int MAX_N = 100000;

int BIT[MAX_N+1];
int n, a[MAX_N];

void add(int x, int i) {
  while (i <= n) {
    BIT[i] += x;
    i += i & (-i);
  }
}

int sum(int i) {
  int ans = 0;
  while (i > 0)
  {
    ans += BIT[i];
    i -= i & (-i);
  }
  return ans;
}

ll solve() {
  memset(BIT, 0, sizeof(BIT));
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += i - sum(a[i]);
    add(1, a[i]);
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = solve();
  cout << ans << endl;
  return 0;
}