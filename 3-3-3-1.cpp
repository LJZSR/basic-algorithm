#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int B = 1000;
const int MAX_N = 100000;
const int MAX_M = 5000;

int A[MAX_N], I[MAX_M], J[MAX_N], K[MAX_N];;
int nums[MAX_N];
vector<int> Buckets[MAX_N/B];

int N, M;

void solve() {
  for (int i = 0; i < N; ++i) {
    Buckets[i/B].push_back(A[i]);
    nums[i] = A[i];
  }
  sort(nums, nums+N);
  for (int i = 0; i < N / B; ++i) {
    sort(Buckets[i].begin(), Buckets[i].end());
  }
  for (int i = 0; i < M; ++i) {
    int l = I[i], r = J[i]+1, k = K[i];
    int lb = 0, rb = N;
    while (rb - lb > 1) {
      int mid = (rb + lb) / 2;
      int x = nums[mid];
      int tl = l, tr = r, c = 0;
      while (tl < tr && tl % B != 0) {
        if (A[tl] < x) ++c;
        ++tl;
      }
      while (tl < tr && tr % B != 0) {
        --tr;
        if (A[tr] < x) ++c;
      }
      while (tl < tr) {
        int b = tl / B;
        c += lower_bound(Buckets[b].begin(), Buckets[b].end(), x) - Buckets[b].begin();
        tl += B;
      }
      if (c > k-1) rb = mid;
      else lb = mid;
    }
    std::cout << nums[lb] << endl;
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> I[i];
    cin >> J[i];
    cin >> K[i];
    I[i]--;
    J[i]--;
  }
  solve();
  return 0;
}