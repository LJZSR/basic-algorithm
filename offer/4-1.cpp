#include<iostream>
#include<vector>

using namespace std;

int findY(vector<vector<int>> input, int target, int end, int x) {
  int begin = -1;
  while (end - begin > 1){
    int mid = (begin + end) / 2;
    if (input[x][mid] <= target) {
      begin = mid;
    }
    else {
      end = mid;
    }
  }
  return begin;
}

int findX(vector<vector<int>> input, int target, int begin, int y) {
  int end = input.size();
  while (end - begin > 1) {
    int mid = (begin + end) / 2;
    if (input[mid][y] >= target) {
      end = mid;
    }
    else {
      begin = mid;
    }
  }
  return end;
}

bool solve(vector<vector<int>> input, int target) {
  if (input.size() == 0) {
    return false;
  }
  int x = 0;
  int y = input[0].size() - 1;
  while (x < input.size() && y >= 0) {
    if (input[x][y] == target) {
      return true;
    }
    if (input[x][y] > target) {
      y = findY(input, target, y, x);
    } 
    else {
      x = findX(input, target, x, y);
    }
  }
  return false;
}

int main() {
  vector<vector<int>> input(4, vector<int>(4));
  input[0][0] = 1;
  input[0][1] = 2;
  input[0][2] = 8;
  input[0][3] = 9;
  input[1][0] = 2;
  input[1][1] = 4;
  input[1][2] = 9;
  input[1][3] = 12;
  input[2][0] = 4;
  input[2][1] = 7;
  input[2][2] = 10;
  input[2][3] = 13;
  input[3][0] = 6;
  input[3][1] = 8;
  input[3][2] = 11;
  input[3][3] = 15;
  int target = 11;
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < input[0].size(); ++j) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
  bool result = solve(input, target);
  if (result) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
}