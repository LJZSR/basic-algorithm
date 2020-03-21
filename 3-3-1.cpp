#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 10000;

int N, C;
int S[MAX_N];

double A[MAX_N], L[MAX_N];
double ang[MAX_N];
double angle[MAX_N];
double vx[MAX_N], vy[MAX_N];

void init(int k, int l, int r) {
  vx[k] = 0.0;
  ang[k] = 0.0;
  if (r - l == 1) {
    vy[k] = L[l];
  }
  else {
    int left = 2 * k + 1;
    int right = 2 * k + 2;
    init(left, l, (l+r)/2);
    init(right, (l+r)/2, r);
    vy[k] = vy[left] + vy[right];
  }
}

void upload(int s, double angle, int index, int l, int r) {
  if (s < l || s >= r) return;
  int mid = (l + r) / 2;
}

void solve1() {
  // init(0, 0, N);

}
void solve2(int s, double a) {
  a = a / 180.0 * M_PI;
  double an = a - angle[s];

  for (int i = s+1; i < N; ++i) {
    double cx = vx[i], cy = vy[i];
    vx[i] = cx * cos(an) - cy * sin(an);
    vy[i] = cy * cos(an) + cx * sin(an);
  }
  double ansx = 0;
  double ansy = 0;
  for (int i = 0; i < N; ++i) {
    ansx += vx[i];
    ansy += vy[i];
  }
  cout << ansx << " " << ansy << endl; 
}

int main() {
  cin >> N >> C;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  for (int i = 0; i < C; ++i) {
    cin >> S[i];
    --S[i];
  }
  for (int i = 0; i < C; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    vx[i] = 0;
    vy[i] = L[i];
    angle[i] = M_PI;
  }
  // for (int i = 0; i < C; ++i) {
  //   solve2(S[i], A[i]);
  // }
  return 0;
}

