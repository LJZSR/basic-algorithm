#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 100000;
const int MAX_T = 100;

int T, N, B;
int result[MAX_T];
int solve() {
  cin >> N >> B;
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 0; i < N; ++i) {
    int c;
    cin >> c;
    pq.push(c);
  }
  int cost = 0;
  int num = 0;
  while (!pq.empty() && cost <= B) {
    int c = pq.top();
    pq.pop();
    if (c + cost <= B) {
      ++num;
    }
    cost += c;
  }
  return num;
}
int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    result[i] = solve();
  }
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": " << result[i] << endl;
  }
  return 0;
}
