#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> res;
void conStr2Int(string str) {
  int ans = 0;
  int i = 0;
  while (i < str.length()) {
    if (str[i] >= '1' && str[i] <= '3') {
      ans = str[i] - '0';
      int j = 1;
      while (i+j < str.length()) {
        if (str[i+j] >= '0' && str[i+j] <= '9') {
          ans = ans * 10 + (str[i+j] - '0');
        } else {
          break;
        }
        ++j;
      }
      if (j == 4 && ans >= 1000 && ans <= 3999) {
        cout << ans << " ";
      }
      i = i + j;
    } else {
      ++i;
    }
  }
}

int main() {
  string in;
  while (cin >> in)
  {
    conStr2Int(in);
  }
  
  return 0;
}