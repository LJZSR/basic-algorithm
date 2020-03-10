#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_P = 1000000;

set<int> allK;
map<int, int> counter;

int a[MAX_P];
int P;

int solve() {
  int ans = P + 1;
  int i = 0, j = 0;
  while (counter.size() != allK.size()) {
    counter[a[j]]++;
    j++;
  }
  ans = min(ans, j-i);
  while (j < P) {
    if (counter[a[i]] > 1) {
      counter[a[i]]--;
      i++;
      ans = min(ans, j-i);
    }
    else {
      counter[a[j]]++;
      j++;
    }
  }
  return ans;
}

int main() {
  cin >> P;
  for (int i = 0; i < P; ++i) {
    cin >> a[i];
    allK.insert(a[i]);
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}