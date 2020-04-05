#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int MAX_N = 100;

int n, k, e;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < B.size(); ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

mat pow(mat &A, int n) {
  mat B(A.size(), vec(A[0].size()));
  for (int i = 0; i < B.size(); ++i) {
    B[i][i] = 1;
  }

  while (n > 0) {
    if ((n & 1) == 1) {
      B = mul(A, B);
      --n;
    }
    else
    {
      A = mul(A, A);
      n = (n >> 1);
    }
  }
  return B;
}

int main() {
  cin >> n >> e;
  mat G(n, vec(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      G[i][j] = 0;
    }
  }

  for (int i = 0; i < e; ++i) {
    int start, end;
    cin >> start >> end;
    G[start][end] = 1;
  }
  cin >> k;
  G = pow(G, k);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += G[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}
