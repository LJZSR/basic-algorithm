#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
const double INF = 1000000;

double w[MAX_N], v[MAX_N];
int n, k;

bool judge(double x) {
  double tmp[n];
  for (int i = 0; i < n; ++i) {
    tmp[i] = v[i] - x * w[i];
  }
  sort(tmp, tmp+n);
  double ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += tmp[n-i-1];
  }
  return ans > 0;
}

double solve() {
  double lb = 0, ub = INF;
  while (ub - lb >= 1e-3) {
    double mid = (lb + ub) / 2;
    if (judge(mid)) {
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  return ub;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  double ans = solve();
  printf("%.2f\n", ans);
  return 0;
}