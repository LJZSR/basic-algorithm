#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T, Q;

void solve() {
  cin >> Q;
  queue<int> q;
  string input;
  getchar();
  for (int i = 0; i < Q; ++i) {
    getline(cin, input);
    int index = 0;
    if (input == "TOP") {
      if (q.empty()) cout << -1 << endl;
      else cout << q.front() << endl;
    }
    else if (input == "POP") {
      if (q.empty()) cout << -1 << endl;
      else q.pop();
    }
    else if (input == "SIZE") {
      cout << q.size() << endl;
    }
    else if (input == "clear") {
      while (!q.empty()) q.pop();
    }
    else
    {
      string tmp = input.substr(5, input.length()-5);
      int param = 0;
      for (int i = 0; i < tmp.length(); ++i) {
        param = param * 10 + (tmp[i]-'0');
      }
      q.push(param);
    }
    
  }
}

int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    solve();
  }
  return 0;
}