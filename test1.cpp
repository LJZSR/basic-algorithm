#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> input;
vector<int> maxThree;
vector<int> minFour;

int solve() {
  for (int i = 0; i < 3; ++i) {
    maxThree.push_back(input[i]);
    minFour.push_back(input[i]);
  }
  minFour.push_back(input[3]);
  sort(minFour.begin(), minFour.end());
  sort(maxThree.begin(), maxThree.end());
  for (int i = 3; i < input.size(); ++i) {
    if (input[i] > maxThree[0]) {
      maxThree[0] = input[i];
      sort(maxThree.begin(), maxThree.end());
    }
    if (input[i] < minFour[3]) {
      minFour[3] = input[i];
      sort(maxThree.begin(), maxThree.end());
    }
  }
  int ans = 0;
  for (int i = 0; i < minFour.size(); ++i) {
    ans += minFour[i];
  }
  for (int i = 0; i < maxThree.size(); ++i) {
    ans += maxThree[i];
  }
  return ans;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    input.push_back(i);
  }
  int ans = solve();
  cout << ans << endl;
  return 0;
}