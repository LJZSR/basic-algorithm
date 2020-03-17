#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int DAT_SIZE = (1 << 18) - 1;
const int MAX_N = 1000, MAX_Q = 100;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

ll data[DAT_SIZE], datb[DAT_SIZE];

void add(int i, int j, int x, int k, int l, int r) {
  if (i <= l && j >= r) {
    data[k] += x;
  }
  else if (l < j && i < r) {
    datb[k] += (min(j, r) - max(i, l)) * x;
    add(i, j, x, 2 * k + 1, l, (l+r)/2);
    add(i, j, x, 2 * k + 2, (l+r)/2, r);
  }
}

ll sum(int i, int j, int k, int l, int r) {
  ll ans = 0;
  if (j <= l || i >= r) ans = 0;
  else if (l >= i && r <= j) {
    ans = (r - l) * data[k] + datb[k];
  }
  else {
    ans = (min(j, r) - max(i, l)) * data[k];
    ans += sum(i, j, 2*k+1, l, (l+r)/2);
    ans += sum(i, j, 2*k+2, (l+r)/2, r);
  }
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    add(i, i+1, A[i], 0, 0, N);
  }
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> T[i];
    if (T[i] == 'C') {
      cin >> L[i] >> R[i] >> X[i];
      add(L[i], R[i]+1, X[i], 0, 0, N);
    }
    else {
      cin >> L[i] >> R[i];
      cout << sum(L[i], R[i]+1, 0, 0, N) << endl;
    }
  }
  return 0;
}