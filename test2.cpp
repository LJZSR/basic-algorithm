#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> words;
string chars;
int used[100];

int solve() {
  int ans = 0;
  for (int i = 0; i < words.size(); ++i) {
    string word = words[i];
    int counter = 0;
    for (int k = 0; k < chars.length(); ++k) {
      used[k] = 0;
    }
    for (int j = 0; j < word.size(); ++j) {
      for (int k = 0; k < chars.length(); ++k) {
        if (word[j] == chars[k] && used[k] == 0) {
          used[k] = 1;
          counter++;
          break;
        }
      }
    }
    if (counter == word.size()) {
      ans += counter;
    }
  }
  return ans;
}

int main() {
  words.push_back("cat");
  words.push_back("bt");
  words.push_back("hat");
  words.push_back("tree");
  chars = "atach";
  int ans = solve();
  cout << ans << endl;
}