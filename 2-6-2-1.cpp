#include <iostream>
#include <cmath>

using namespace std;

int n = 0;
int main() {
  bool flag = true;
  cin >> n;
  if (n == 1) { 
    flag = false;
    cout << "No" << endl;
  }
  else {
    for (int i = 2; i <= sqrt(n); ++i) {
      if (n % i == 0) {
        flag = false;
        cout << "No" << endl;
        break;
      }
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  }
  return 0;
}