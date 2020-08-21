#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> waimaiOrder;
int n, m;

int getParent(int s) {
  if (waimaiOrder[s] == s)
    return s;
  else
    return waimaiOrder[s] = getParent(waimaiOrder[s]);
}

void merge(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x != y) {
    waimaiOrder[y] = x;
  }
}

int main() {
  cin >> n >> m;
  //初始化并查集
  for (int index = 0; index < n; ++index) {
    waimaiOrder.push_back(index);
  }
  for (int index = 0; index < m; ++index) {
    int a, b;
    cin >> a >> b;
    merge(a-1, b-1);
  }
  vector<vector<int> > result(n, vector<int>());
  int sum = 0;
  for (int index = 0; index < n; ++index) {
    int j = index;
    while (waimaiOrder[j] != j) {
      j = getParent(j);
    }
    result[j].push_back(index);
  }
  for (int index = 0; index < n; ++index) {
    if (result[index].size() > 0) {
      sort(result[index].begin(), result[index].end());
      ++sum;
    }
  }
  cout << sum << endl;
  //处理输出顺序
  vector<pair<int, int> > temp;
  for(int index = 0; index < n; ++index) {
    if (result[index].size() > 0) {
      temp.push_back(make_pair(result[index][0], index));
    }
  }
  sort(temp.begin(), temp.end());
  for (int index = 0; index < temp.size(); ++index) {
    for (int j = 0; j < result[temp[index].second].size(); ++j) {
      cout << result[temp[index].second][j]+1 << " ";
    }
    cout << endl;
  }
}