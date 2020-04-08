#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;

int n, k, M;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < A[0].size(); ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

mat pow(mat &A, int n) {
  mat B(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    B[i][i] = 1;
  }
  while (n > 0)
  {
    if ((n & 1) == 1) {
      B = mul(A, B);
      --n;
    }
    else {
      A = mul(A, A);
      n = (n >> 1);
    }
  }
  return B;
}

mat solve(mat &A) {
  mat B(2 * n, vec(2 * n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      B[i][j] = A[i][j];
    }
    B[i+n][i] = 1;
    B[i+n][i+n] = 1;
  }
  B = pow(B, k+1);
  mat S(n, vec(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      S[i][j] = B[i+n][j] % M;
    }
    S[i][i] = (S[i][i] - 1 + M) % M;
  }
  return S;
}

int main() {
  cin >> n >> k >> M;
  mat A(n, vec(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> A[i][j];
    }
  }
  mat S = solve(A);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << S[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}