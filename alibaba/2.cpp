#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n, m;
vector<int> a;


int solve() {
  int res = 0;
  int i = 0;
  int j = 0;
  map<int, int> flag;
  if (m == 1) {
    return (1+n)*n/2;
  }
  while (j < n) {
    while (j < n && flag[a[j]] < m) {
      flag[a[j]]++;
      if (flag[a[j]] == m) break;
      j++;
    }
    if (j != n) {
      cout << i << " " << j << endl;
      res += n - j;
      while (i < j) {
        flag[a[i]]--;
        ++i;
        if (flag[a[j]] == m) {
          cout << i << " " << j << endl;
          res += n - j;
        }
        else {
          break;
        }
      }
      ++j;
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  int res = solve();
  cout << res << endl;
}