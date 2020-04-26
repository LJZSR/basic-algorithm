#include <iostream>

typedef long long ll;

using namespace std;

ll x;
int k, Q;

int main() {
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> x >> k;
    int depth = 0;
    ll tmp = x;
    while (tmp > 0) {
      tmp = (tmp >> 1);
      ++depth;
    }
    if (depth <= k) {
      cout << -1 << endl;
      continue;
    }
    else k = depth - k;
    for (int i = 0; i < k; ++i) {
      x = (x >> 1);
    }
    cout << x << endl;
  }
  return 0;
}
