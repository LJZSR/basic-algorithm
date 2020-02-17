#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 10000;

int N = 0, L = 0, P = 0;
int A[MAX_N], B[MAX_N];

int solve() {

  priority_queue<int> pque;
  int ans = 0;
  int station = 0;
  for (int i = 0; i < N && A[i] <= P; ++i) {
    pque.push(B[i]);
    station = i;
  }
  int currentL = P;
  while (currentL < L && !pque.empty()) {
    currentL += pque.top();
    pque.pop();
    ans++;
    for (int i = station + 1; i < N && A[i] <= currentL; ++i) {
      pque.push(B[i]);
      station = i;
    }
  }
  if (currentL >= L) return ans;
  else return -1;
}

int main() {
  cin >> N >> L >> P;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}