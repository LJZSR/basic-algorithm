#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 4000;

int CD[MAX_N * MAX_N];

int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int n;

long long solve() {
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      CD[i*n+j] = C[i] + D[j];
    }
  }
  sort(CD, CD+n*n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int target = -A[i]-B[j];
      ans += upper_bound(CD, CD+n*n, target) - lower_bound(CD, CD+n*n, target);
    }
  } 
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> B[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> C[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> D[i];
  }

  long long ans = solve();
  cout << ans << endl;
}