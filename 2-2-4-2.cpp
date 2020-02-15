#include <iostream>
#include <algorithm>

using namespace std;

const int  MAX_N = 20000;
int N;
int L[MAX_N];

int solve(int n) {
  if (n == N - 1) {
    return L[N];
  }
  sort(L + n, L + N);
  ++n;
  L[n] = L[n-1] + L[n];
  return (L[n] +solve(n));
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  int n = 0;
  int ans = solve(n);
  cout << ans << endl;
  return 0;
}