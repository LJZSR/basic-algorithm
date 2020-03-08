#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX_N = 10000;
const double INF = 100000;

int N, K;
double L[MAX_N];

bool isRight(double x) {
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += (int)floor(L[i] / x);
  }
  return ans >= K;
}

double solve() {
  double first = 0, last = INF;
  while (last - first >= 1e-4) {
    double mid = (last+first) / 2;
    if (isRight(mid)) {
      first = mid;
    }
    else {
      last = mid;
    }
  }
  return last;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  double ans = solve();
  printf("%.2f\n", floor(ans * 100) / 100);
  return 0;
}