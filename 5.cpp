#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1000;
int n;
int minNumberInRotateArray(vector<int> rotateArray) {
  if (rotateArray.size() == 0) return 0;
  int l = -1;
  int r = rotateArray.size()-1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (rotateArray[mid] <= rotateArray[r]) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  return r;
}

int main () {
  
}