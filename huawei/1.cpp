#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> input;

int solve(vector<string> & input, int i) {
  if (i == input.size()) {
    return 1;
  }
  if (i > input.size()) {
    return 0;
  }
  if (input[i] == "AND" || input[i] == "OR") {
    if (input.size() >= i+2 && input[i+1].size() == 1 && input[i+1] >= "a" && input[i+2] <= "z") {
      return solve(input, i+2);
    }
  }
  return 0;
}

int main() {
  string str;
  while (getline(cin, str)) {
    int begin = 0;
    for (int i = 1; i <= str.size(); ++i) {
      if (i == str.size() || str[i] == ' ') {
        input.push_back(str.substr(begin, i-begin));
        begin = i + 1;
      }
    }
    int ans = -1;
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == "NOT") {
        if (i+1 < input.size()-1 && input[i+1] == "NOT") {
          ans = 0;
          break;
        }
      } 
    }
    while (find(input.begin(), input.end(), "NOT") != input.end()) {
      input.erase(find(input.begin(), input.end(), "NOT"));
    }
    if (ans == 0) {
      cout << ans << endl;
    }
    else {
      if (input[0].size() == 1 && input[0] >= "a" && input[0] <= "z") {
        ans = solve(input, 1);
        cout << ans << endl;
      }
      else
      {
        ans = 0;
        cout << ans << endl;
      }
    }
    input.clear();
  }
  return 0;
}