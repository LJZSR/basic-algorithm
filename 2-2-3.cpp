#include <iostream>

using namespace std;

const int MAX_N = 2000;
char S[MAX_N];
char T[MAX_N];

int N;

void solve() {
  int i = 0, j = N - 1;
  int k = 0;
  while (k < N) {
    bool flagFront = true;
    int tmpi = i;
    int tmpj = j;
    while (tmpi < tmpj) {
      if (S[tmpi] < S[tmpj]) {
        flagFront = true;
        break;
      }
      else if (S[tmpi] > S[tmpj]) {
        flagFront = false;
        break;
      }
      else {
        tmpi++;
        tmpj--;
      }
    }
    if (flagFront) {
      T[k] = S[i];
      ++i;
    }
    else {
      T[k] = S[j];
      --j;
    }
    ++k;
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
  for (int i = 0; i < N; ++i) {
    cout << T[i];
  }
  cout << endl;
  return 0;
}