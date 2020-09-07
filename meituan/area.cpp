#include<iostream>

using namespace std;

const int MAX_N = 100001;

int a[MAX_N];

int n, p, q;

int main() {
  cin >> n >> p >> q;
  for (int i = 0; i < n; ++i) {
    a[i+1] = 0;
  }
  for (int i = 0; i < p; ++i) {
    int tmp;
    cin >> tmp;
    a[tmp] = 1;
  }

  int A = p, B = 0, C = 0;
  for (int i =0; i < q; ++i) {
    int tmp;
    cin >> tmp;
    if (a[tmp] == 1) {
      A--;
      C++;
    }
    else {
      B++;
    }
  }
  cout << A << " " << B << " " << C << endl;
}