#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1 << 17;
const int MAX_N = 50000;
const int MAX_M = 500000;
const int INF = MAX_M + 1;


int dat[2 * MAX_SIZE - 1];

int size;
int n, m;
int s[MAX_M], t[MAX_M];
int dp[MAX_N+1];

void init(int _n) {
  size = 1;
  while (size < _n) size *= 2;
  for (int i = 0; i < 2 * size - 1; ++i) {
    dat[i] = INF;
  }
}

void updata(int k, int a) {
  int index = k + size - 1;
  dat[index] = a;
  while (index > 0) {
    index = (index - 1) / 2;
    dat[index] = min(dat[2 * index + 1], dat[2 * index + 2]);
  }
}

int query(int a, int b, int k, int l, int r) {
  if (l >= b || r <= a) return INF;
  if (l >= a && r <= b) return dat[k];
  else {
    int vl = query(a, b, 2 * k + 1, l, (l+r)/2);
    int vr = query(a, b, 2 * k + 2, (l+r)/2, r);
    return min(vl, vr);
  }
}

int solve() {
  init(n+1);
  updata(1, 0);
  for (int i = 0; i <= n; ++i) {
    dp[i] = INF;
  }
  dp[1] = 0;
  for (int i = 0; i < m; ++i) {
    int v = min(dp[t[i]], query(s[i], t[i]+1, 0, 0, size+1)+1);
    dp[t[i]] = v;
    updata(t[i], v);
  }
  return dp[n];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s[i] >> t[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}

