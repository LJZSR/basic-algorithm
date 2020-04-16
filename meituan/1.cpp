#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 500;
const int MAX_M = 500;
set<int> c;

int n, m;
int score[MAX_N][MAX_M];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
          cin >> score[i][j];
      }
  }
  for (int j = 0; j < m; ++j) {
    int max = 0;
    vector<int> stu;
    for (int i = 0; i < n; ++i) {
      if (score[i][j] > max) {
        max = score[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (score[i][j] == max) {
        stu.push_back(i);
      }
    }
    for (int i = 0; i < stu.size(); ++i) {
      if (c.find(stu[i]) == c.end()) {
        c.insert(stu[i]);
      }
    }
  }
  cout << c.size() << endl;
  return 0;
}