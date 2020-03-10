#include <iostream>

using namespace std;

const int MAX_N = 5000;
int f[MAX_N];

int N;
int a[MAX_N];
int M, K;

int calK(int k) {
  for (int i = 0; i < N; ++i) {
    f[i] = 0;
  }
  int ans = 0;
  int sum = 0;
  for (int i = 0; i+k <= N; ++i) {
    if ((a[i] + sum) % 2 != 0) {
      ans++;
      f[i] = 1;
      sum++;
    }
    if (i-k+1 >= 0) {
      sum -= f[i-k+1];
    }
  }
  for (int i = N + 1 - k; i < N ; ++i) {
    if ((a[i] + sum) % 2 != 0) {
      return -1;
    }
    if (i-k+1 >= 0) {
      sum -= f[i-k+1];
    }
  }
  return ans;
}

void solve() {
  M = N;
  K = 1;
  for (int i = 1; i <= N; ++i) {
    int m = calK(i);
    if (m >= 0 && m < M) {
      M = m;
      K = i;
    }
  }
}

int main() {
  char ch;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> ch;
    if (ch == 'B') {
      a[i] = 1;
    }
    else {
      a[i] = 0;
    }
  }
  solve();
  cout << "M = " << M << endl;
  cout << "K = " << K << endl;
  return 0;
}