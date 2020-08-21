#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> frame;
vector<int> brick;

int solvePair(int p, int q) {
  vector<int> helper;
  for (int i = 0; i < frame.size(); ++i) {
    helper.push_back(frame[i]);
  }
  int index = p - q;
  if (index < 0) return INT16_MAX;
  int top = 0;
  int i = 0;
  while (i < brick.size()) {
    int tmp = frame[index] + brick[i];
    top = (tmp > top) ? tmp : top;
    ++index;
    ++i;
    if (index == frame.size() && i != brick.size()) {
      return INT16_MAX;
    } 
  }
  index = p - q;
  for (i = 0; i < brick.size(); ++i) {
    int tmp = frame[index] + brick[i];
    if (tmp == top) {
      helper[index] = top;
    } 
    ++index;
  }
  int res = helper[0];
  for (int i = 0; i < helper.size(); ++i) {
    res = (res < helper[i]) ? res : helper[i];
  }
  return top-res;
}

int solve() {
  int res = INT16_MAX;
  int min = frame[0];
  int max = brick[0];
  for (int i = 1; i < frame.size(); ++i) {
    min = (frame[i] < min) ? frame[i] : min;
  }
  for (int i = 1; i < brick.size(); ++i) {
    max = (brick[i] > max) ? brick[i] : max;
  }
  vector<int> frameIndex;
  vector<int> brickIndex;
  for (int i = 0; i < frame.size(); ++i) {
    if (frame[i] == min) {
      frameIndex.push_back(i);
    }
  }
  for (int i = 0; i < brick.size(); ++i) {
    if (brick[i] == max) {
      brickIndex.push_back(i);
    }
  }
  for (int i = 0; i < frameIndex.size(); ++i) {
    for (int j = 0; j < brickIndex.size(); ++j) {
      int ans = solvePair(frameIndex[i], brickIndex[j]);
      res = (ans < res) ? ans : res;
    }
  }
  return res;
}

int main() {
  string tmpFrame;
  cin >> tmpFrame;
  string tmpBrick;
  cin >> tmpBrick;
  for (int i = 0; i < tmpFrame.length(); ++i) {
    frame.push_back(tmpFrame[i]-'0');
  }
  for (int i = 0; i < tmpBrick.length(); ++i) {
    brick.push_back(tmpBrick[i] - '0');
  }

  int ans = solve();
  cout << ans << endl;
}
