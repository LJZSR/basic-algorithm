#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n, k;
int input[500];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  sort(input, input+n);
  int *index1 = lower_bound(input, input+n, k);
  int *index2 = upper_bound(input, input+n, k);
  int x = index2 - index1;
  int l = index1 - input;
  int m = n - l - x;
  int result = 0;
  if (x == 0) {
    result++;
    x = 1;
  }
  int mid = (l + x + m + 1) / 2;
  if (mid >= l+1 && mid <= l+x) {
    cout << result << endl;
    return 0;
  }
  if (mid <= l) {
    int i = 0;
    while (true) {
      int mid = (l + x + m + i + 1) / 2;
      if (mid >= l+1) {
        cout << result + i << endl;
        return 0;
      }
      else {
        ++i;
      }
    }
  }
  if (m > l+x) {
    int i = 0;
    while (true) {
      int mid = (l + x + m + i + 1) / 2;
      if (mid <= l + x + i) {
        cout << result + i << endl;
        return 0;
      } 
      else {
        ++i;
      }
    }
  }
}