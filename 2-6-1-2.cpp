#include <iostream>

using namespace std;

int a = 0, b = 0;
int x = 0, y = 0;

int exgcd(int a, int b, int &x, int &y) {
  int ans = a;
  if (b == 0) {
    x = 1;
    y = 0;
  }
  else {
    ans = exgcd(b, a%b, x, y);
    int tmp = y;
    y = x - (a/b)*y;
    x = tmp;
  }
  return ans;
}

int main() {
  cin >> a >> b;
  int ans = exgcd(a, b, x, y);
  if (ans == 1) {
    cout << x << " " << y << endl;
  }
  else {
    cout << -1 << endl;
  }
  return 0;
}