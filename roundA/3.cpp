#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pos;

const int MAX_N = 100000;

int T;
int N, K;
int M[MAX_N];

void solve(int m) {
  priority_queue<pos> pq;
  for (int i = 0; i < N-1; ++i) {
    pq.push(make_pair(M[i+1]-M[i], M[i]));
  }
  int c = 0;
  while (pq.top().first != 1 && c < K) {
    pos p = pq.top();
    pq.pop();
    int left = p.second;
    int right = p.first + p.second;
    int mid = (left + right) / 2;
    pq.push(make_pair(mid-left, left));
    pq.push(make_pair(right-mid, mid));
    ++c;
  }
  cout << "Case #" << m+1 << ": " << pq.top().first << endl;
}
int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N >> K;
    for (int j = 0; j < N; ++j) {
      cin >> M[j];
    }
    solve(i);
  }
}
