#include <iostream>

using namespace std;

int x1, y1, x2, y2;

int gcd(int x, int y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

int solve() {
  int d1 = abs(x1-x2);
  int d2 = abs(y1-y2);
  if (d1 == 0 && d1 == d2) return 0;
  else return gcd(d1, d2)-1;
}

int main() {
  cin >> x1 >> y1 >> x2 >> y2;
  int ans = solve();
  cout << ans << endl;
  return 0;
}