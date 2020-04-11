#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1000;
int oldUser[MAX_N][MAX_N];
int newUser[MAX_N][MAX_N];
int resultNew[MAX_N];
int resultOld[MAX_N];
int n;
int num = 0;

int tmp[MAX_N];

void solve() {
  for (int i = 0; i < n; ++i) {
    resultNew[i] = -1;
    resultOld[i] = -1;
    tmp[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      tmp[j] = 0;
    }
    for (int j = 0; j < n; ++j) {
      tmp[newUser[j][i]]++;
    }
    for (int j = 0; j < n; ++j) {
      if (tmp[j] == 1 && resultOld[j] == -1) {
        for (int k = 0; k < n; ++k) {
          if (newUser[k][i] == j) {
            resultNew[k] = j;
            resultOld[j] = k;
          }
        }
      }
      if (tmp[j] >= 2 && resultOld[j] == -1) {
        for (int k = 0; k < n; ++k) {
          if (newUser[i][oldUser[j][k]])
        }
      }
    }
  }
  
}

int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int index;
    cin >> index;
    --index;
    for (int j = 0; j < n; ++j) {
      cin >> newUser[index][j];
      newUser[index][j]--;
    }
  }
  for (int i = 0; i < n; ++i) {
    int index;
    cin >> index;
    --index;
    for (int j = 0; j < n; ++j) {
      cin >> oldUser[index][i];
      oldUser[index][j]--;
    }
  }
  solve();
  return 0;
}
