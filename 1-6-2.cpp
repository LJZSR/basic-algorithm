#include<iostream>

using namespace std;

void solve(int L, int n, int x[], int result[]);

int main() {
  int L = 0, n = 0;
  cin >> L >> n;
  int x[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int result[2];
  result[0] = 0;
  result[1] = 0;
  solve(L, n, x, result);
  cout << "min = " << result[0] << endl;
  cout << "max = " << result[1] << endl;
  return 0;
}

void solve(int L, int n, int x[], int result[]) {
  for (int i = 0; i < n; ++i) {
    int max = x[i] > (L - x[i]) ? x[i] : (L - x[i]);
    int min = x[i] < (L - x[i]) ? x[i] : (L - x[i]);
    result[0] = result[0] > min ? result[0] : min;
    result[1] = result[1] > max ? result[1] : max;
  }
}