#include <iostream>

using namespace std;

bool dfs(int i, int sum, int k, int n, int a[]);

int main() {
  int n = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k = 0;
  cin >> k;

  bool result = dfs(0, 0, k, n, a);
  if (result) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}

bool dfs(int i, int sum, int k, int n, int a[]) {
  // i: 目前检查到第i项
  // sum: 前i-1项和
  // k: 目标和
  // n: 总项数
  // a[]: 输入序列
  if (i == n) return sum == k; //已经检查完最后一项

  // 不加入第i项
  if (dfs(i + 1, sum, k, n, a)) {
    return true;
  }

  //加入第i项
  if (dfs(i + 1, sum + a[i], k, n, a)) {
    return true;
  }

  return false;
}