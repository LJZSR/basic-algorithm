#include <iostream>
#include <vector>

using namespace std;

int T, K, N;

int solve(vector<int> &a, int K) {
  int ans = 0;
  int i = 0;
  while (i < a.size()) {
    if (a[i] == K) {
      int j = i+1;
      while (j < a.size() && K-j+i > 0) {
        if (a[j] == K-j+i) {
          ++j;
        }
        else
        {
          break;
        }
      }
      if (K-j+i == 0) {
        ++ans;
        i = j;
      }
      else {
        i = j;
      }
    }
    else
    {
      ++i;
    }
  }
  return ans;
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cin >> N >> K;
    vector<int> a;
    for (int i = 0; i < N; ++i) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    int ans = solve(a, K);
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}