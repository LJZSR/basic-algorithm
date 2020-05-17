#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e7;
bool flag[MAX_N];

int T, N;

int solve(vector<int> &a) {
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < a.size(); ++i) {
    sum = a[i];
    if (flag[sum]) {
      ++ans;
    }
    for (int j = i+1; j < a.size(); ++j) {
      sum += a[j];
      if (flag[sum]) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  for (int i = 0; i < MAX_N; ++i) {
    flag[i] = false;
  }
  for (int i = 0; i < 3162; ++i) {
    flag[i*i] = true;
  }
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cin >> N;
    vector<int> a;
    for (int j = 0; j < N; ++j) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    int ans = solve(a);
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}