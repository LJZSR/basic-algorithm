#include <iostream>

using namespace std;

int solve(int a[], int n);
int max3(int i, int j, int k);

int main() {
  const int MAX_N = 1e6;
  int n, a[MAX_N];

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = solve(a, n);
  
  cout << ans << endl;

  return 0;
}

int solve(int a[], int n) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int len = a[i] + a[j] + a[k];
        int ma = max3(a[i], a[j], a[k]);
        int res = len - ma;
        if (res > ma) {
          ans = ans > len ? ans : len;
        }
      }
    }
  }
  return ans;
}

int max3(int i, int j, int k) {
  int tmp = i > j ? i : j;
  return tmp > k ? tmp : k;
}