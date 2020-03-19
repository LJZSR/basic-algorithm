#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int ST_SIZE = (1 << 18) - 1;
const int MAX_N = 100000;
const int MAX_M = 5000;

int N, M;
int A[MAX_N], I[MAX_M], J[MAX_M], K[MAX_N];

int nums[MAX_N];
vector<int> dat[ST_SIZE];

void init(int k, int l, int r) {
  if (r-l == 1) {
    dat[k].push_back(A[l]);
  }
  else
  {
    init(2*k+1, l, (l+r)/2);
    init(2*k+2, (l+r)/2, r);
    dat[k].resize(r-l);
    merge(dat[2*k+1].begin(), dat[2*k+1].end(), dat[2*k+2].begin(), dat[2*k+2].end(), dat[k].begin());
  }
}

int query(int x, int i, int j, int k, int l, int r) {
  if (j <= l || i >= r) {
    return 0;
  }
  else if (i <= l && j >= r) {
    return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
  }
  else {
    int cl = query(x, i, j, 2*k+1, l, (l+r)/2);
    int cr = query(x, i, j, 2*k+2, (l+r)/2, r);
    return cl + cr;
  }
}

void solve() {
  init(0, 0, N);
  for (int i = 0; i < N; ++i) {
    nums[i] = A[i];
  }
  sort(nums, nums+N);
  for (int i = 0; i < M; ++i) {
    int l = I[i];
    int r = J[i] + 1;
    int k = K[i];
    int lb = -1, rb = N-1;
    while (rb - lb > 1) {
      int mid = (rb + lb) / 2;
      int c = query(nums[mid], l, r, 0, 0, N);
      if (c >= k) rb = mid;
      else lb = mid;
    }
    cout << nums[rb] << endl;
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