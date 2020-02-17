#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 20000;

int N;
int L[MAX_N];

int solve() {
  priority_queue<int, vector<int>, greater<int> > pque;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    pque.push(L[i]);
  }
  while (pque.size() >= 2) {
    int one = pque.top();
    pque.pop();
    int two = pque.top();
    pque.pop();
    ans += one + two;
    pque.push(one + two);
  }
  return ans;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}