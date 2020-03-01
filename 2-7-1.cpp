#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N = 800;

int n;
int v1[MAX_N], v2[MAX_N];

ll solve() {
  ll ans = 0;
  sort(v1, v1+n);
  sort(v2, v2+n);
  for (int i = 0; i < n; ++i) {
    ans += (ll)v1[i] * v2[n-i-1];
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> v2[i];
  }
  ll ans = solve();
  cout << ans << endl;
  return 0;
}