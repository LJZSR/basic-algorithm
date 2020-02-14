#include <iostream>

using namespace std;

const int val[6] = {1, 5, 10, 50, 100, 500};
int num[6];

int solve(int A) {
  int ans = 0;
  for (int i = 5; i >= 0; --i) {
    if (val[i] * num[i] <= A) {
      ans += num[i];
      A -= val[i] * num[i];
    }
    else
    {
       ans += A / val[i];
       A %= val[i];
    }
  }
  return ans;
}

int main() {
  for (int i = 0; i < 6; ++i) {
    cin >> num[i];
  }
  int A = 0;
  cin >> A;
  int ans = solve(A);
  cout << ans << endl;
  return 0;
}