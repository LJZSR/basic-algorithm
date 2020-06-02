#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int M, N;
int C[MAX_N];

int find_p(int C[], int begin, int end, int target) {
  while (end - begin > 1) {
    int mid = (end + begin) / 2;
    if (C[mid] <= target) begin = mid;
    else end = mid;
  }
  return begin;
}

int find_q(int C[], int begin, int end, int target) {
  while (end - begin > 1) {
    int mid = (end + begin) / 2;
    if (C[mid] >= target) end = mid;
    else begin = mid;
  }
  return end;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  sort(C, C+N);
  for (int i = 0; i < M; ++i) {
    int p = 0;
    int q = N-1;
    if (C[q] - C[p] <= 1) break;
    p = find_p(C, 0, N, C[p]);
    q = find_q(C, -1, N-1, C[q]);
    C[p]++;
    C[q]--;
  }
  cout << C[N-1]-C[0] << endl;
  return 0;
}