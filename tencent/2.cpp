#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

const int MAX_N = 100000;

int n;
int T;
int xA[MAX_N], yA[MAX_N], xB[MAX_N], yB[MAX_N];

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> xA[i] >> yA[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> xB[i] >> yB[i];
  }
  double result = double(INT_MAX);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      double dx = xA[i] - xB[j];
      double dy = yA[i] - yB[j];
      double dist = sqrt(dx * dx + dy * dy);
      result = result < dist ? result : dist;
    }
  }
  printf("%.3f\n", result);
}

int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    solve();
  }
  return 0;
}