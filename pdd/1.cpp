#include <iostream>

using namespace std;

typedef long long ll;

int T;
ll N, K;

void solve() {
  cin >> N >> K;
  int c = N - 1;
  int result = 0;
  if (K % c == 0) {
    result = (K / c - 1) * N + c;
  }
  else {
    result = (K / c) * N + K % c;
  }
  cout << result << endl;
}
int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    solve();
  }
  return 0;
}