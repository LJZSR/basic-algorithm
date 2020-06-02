#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 100000;

int A[MAX_N], B[MAX_N];
int N;
priority_queue<pair<int, int> > q;

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    q.push(make_pair(A[i]-B[i], i));
  }
  int result = 0;
  int c = 0;
  while (!q.empty()) {
    int index = q.top().second;
    if (c+A[index] <= result) {
      c += B[index];
    }
    else {
      result += c + A[index] - result;
      c += B[index];
    }
    q.pop();
  }
  cout << result << endl;
  return 0;
}
