#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200000;
int dp[MAX_N][MAX_N];
int T, N, Q;

void init(vector<int> &a) {
  for (int i = 0; i < a.size(); ++i) {
    dp[i][i] = a[i];
    int flag = -2;
    for (int j = i+1; j < a.size(); ++j) {
      dp[i][j] = dp[i][j-1] + flag * a[j];
      flag = flag < 0 ? --flag : ++flag;
      flag = -1 * flag;
    }
  }
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cin >> N >> Q;
    vector<int> a;
    int ans = 0;
    for (int j = 0; j < N; ++j) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    init(a);
    for (int j = 0; j < Q; ++j) {
      char op;
      cin >> op;
      if (op == 'U') {
        int x, v;
        cin >> x >> v;
        a[x-1] = v;
        init(a);
      }
      else {
        int l, r;
        cin >> l >> r;
        ans += dp[l-1][r-1];
      }
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}