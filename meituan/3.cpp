#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<double> input;

ll n, k;
int main() {
  cin >> n >> k;
  for (ll i = 0; i < n; ++i) {
    double tmp;
    cin >> tmp;
    input.push_back(tmp);
  }
  sort(input.begin(), input.end());
  ll i = 0, j = 0;
  if (k % n == 0) {
    i = k / n - 1;
    j = n - 1;
  }
  else {
    i = k / n;
    j = k % n - 1;
  }
  cout << "(" << input[i] << "," << input[j] << ")" << endl;
  return 0;
}