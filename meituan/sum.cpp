#include <iostream>

using namespace std;

int tmp = 0;
int n;

int main() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int mod = n % i;
    int div = n / i;
    if (div % 2 == 0) {
      for (int j = 1; j <= mod; ++j) {
        tmp = tmp ^ j;
      }
    }
    else {
      for (int j = mod + 1; j <= i-1; ++j) {
        tmp = tmp ^ j;
      }
    }
  }
  int res = tmp;
  int a = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    res = res ^ a;
  }
  cout << res << endl;
}