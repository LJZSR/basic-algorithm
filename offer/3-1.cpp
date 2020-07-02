#include<vector>
#include<iostream>

using namespace std;

bool solve(vector<int> &input, int &result) {
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] >= input.size() || input[i] < 0) {
      return false;
    }
  }
  for (int i = 0; i < input.size(); ++i) {
    while (input[i] != i) {
      if (input[input[i]] == input[i]) {
        result = input[i];
        return true;
      }
      int tmp = input[i];
      input[i] = input[tmp];
      input[tmp] = tmp;
    }
  }
  return false;
}

int main() {
  vector<int> input = {2, 3, 1, 0, 6, 5, 4};
  int result;
  bool res = solve(input, result);
  cout << res << endl;
  if (res) {
    cout << result << endl;
  }
  return 0;
}