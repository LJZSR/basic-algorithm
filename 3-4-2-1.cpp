#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int M = 10000;

int n;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < B.size(); ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j] % M;
      }
    }
  }
  return C;
}

mat pow(mat A, int n) {
  mat B(A.size(), vec(A.size()));
  //B = I
  for (int i = 0; i < B.size(); ++i) {
    B[i][i] = 1;
  }
  while (n > 0) {
    if ((n & 1) == 1) {
      B = mul(A, B);
      --n;
    }
    else {
      A = mul(A, A);
      n = n >> 1;
    }
  }
  return B;
}

int main() {
  cin >> n;
  mat A(2, vec(2));
  A[0][0] = 1;
  A[0][1] = 1;
  A[1][0] = 1;
  A[1][1] = 0;
  A = pow(A, n);
  cout << A[1][0] << endl;
}