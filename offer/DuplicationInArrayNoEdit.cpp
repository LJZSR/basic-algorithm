#include<vector>
#include<iostream>

using namespace std;

int countBetween(vector<int> &input, int begin, int end) {
  int res = 0;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] >= begin && input[i] <= end) {
      ++res;
    }
  }
  return res;
}

int solve(vector<int> &input) {
  int begin = 1;
  int end = input.size() - 1;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    int count = countBetween(input, begin, mid);
    if (end == begin) {
      if (count > 1) {
        return mid;
      }
      else {
        break;
      }
    }
    else if (count > mid - begin + 1) {
      end = mid;
    }
    else {
      begin = mid + 1;
    }
  }
  return -1;
}

int main() {
  vector<int> input = {1, 1};
  int res = solve(input);
  cout << res << endl;
  return res;
}