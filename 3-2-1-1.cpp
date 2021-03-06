#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

int S, n;
int a[MAX_N];
int sum[MAX_N+1];

int bSearch(int target, int i) {
  int lb = i;
  int ub = n+1;
  while (lb != ub) {
    int mid = (lb + ub) / 2;
    if (sum[mid] >= target) {
      ub = mid;
    }
    else
    {
      lb = mid + 1;
    }
  }
  if (ub == n+1) return -1;
  else return ub;
}

int solve1() {
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1] + a[i-1];
  }
  if (sum[n] < S) return 0;
  int ans = n+1;
  for (int i = 0; i <n; ++i) {
    int target = S + sum[i];
    int j = bSearch(target, i+1);
    if (j != -1) {
      ans = min(j-i, ans);
    }
  }
  return ans;
}

int solve2() {
  int ans = n + 1;
  int i = 0, j = 0;
  int sum = 0;
  while (j <= n) {
    if (sum >= S) {
      ans = min(ans, j - i);
      sum -= a[i];
      ++i;
    }
    else {
      if (j != n) {
        sum += a[j];
      }
      ++j;
    }
  }
  if (ans == n+1) {
    return 0;
  }
  return ans;
}

int main() {
  cin >> n >> S;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // int ans = solve1();
  int ans = solve2();
  cout << ans << endl;
  return 0;
}