#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1e13;
const int MAX_N = 40;

pair<ll, ll> halfwv[1 << (MAX_N/2)];

int n, w[MAX_N], v[MAX_N], W;

ll solve() {
  int half = n / 2;
  for (int i = 0; i < 1 << half; ++i) {
    int j = i;
    int counter = 0;
    ll tmpw = 0, tmpv = 0;
    while (j > 0) {
      if ((j & 1) == 1) {
        tmpw += w[counter];
        tmpv += v[counter];
      }
      j = j >> 1;
      counter++;
    }
    halfwv[i] = make_pair(tmpw, tmpv);
  }
  sort(halfwv, halfwv+(1 << half));
  int m = 1;
  for (int i = 1; i < 1 << half && halfwv[i].first <= W ; ++i) {
    if (halfwv[m-1].second < halfwv[i].second) {
      halfwv[m] = halfwv[i];
      ++m;
    }
  }

  ll ans = 0;

  for (int i = 0; i < (1 << (n - half)); ++i) {
    int j = i;
    int counter = 1;
    ll tmpw = 0, tmpv = 0;
    while (j > 0) {
      if ((j & 1) == 1) {
        tmpw += w[n - counter];
        tmpv += v[n - counter];
      }
      j = j >> 1;
      ++counter;
    }

    if (tmpw <= W) {
      ll halfAns = (lower_bound(halfwv, halfwv+m, make_pair(W-tmpw, INF))-1) -> second;
      ans = max(ans, halfAns + tmpv);
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cin >> W;
  ll ans = solve();
  cout << ans << endl;
  return 0;
}