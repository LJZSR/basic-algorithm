#include <iostream>
#include <cmath>

using namespace std;

const double g = 10.0;
const int MAX_N = 100;

double y[MAX_N];
int N, H, R, T;

double calc(double T) {
  if (T < 0) return H;
  double t = sqrt(2.0 * H / g);
  int k = T / t;
  if (k % 2 == 0) {
    double d = T - k*t;
    return H - g * d * d / 2.0;
  }
  else {
    double d = k * t + t - T;
    return H - g * d * d / 2.0;
  }
}

void solve() {
  for (int i = 0; i < T; ++i) {
    y[i] = calc(T - i);
  }
}

int main() {
  cin >> N >> H >> R >> T;
  solve();
  for (int i = 0; i < N; ++i) {
    cout << y[i] + 2 *  R * i / 100.0 << " ";
  }
  cout << endl;
}