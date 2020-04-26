#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st1;
stack<int> st2;

int N;

int main() {
  cin >> N;
  getchar();
  string input;
  for (int i = 0; i < N; ++i) {
    getline(cin, input);
    if (input == "peek") {
      if (st2.empty()) {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
      }
      cout << st2.top() << endl;
    }
    else if (input == "poll") {
      if (st2.empty()) {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
      }
      st2.pop();
    }
    else {
      string tmp = input.substr(4, input.length()-4);
      int param = 0;
      for (int i = 0; i < tmp.length(); ++i) {
        param = param * 10 + (tmp[i]-'0');
      }
      st1.push(param);
    }
  }
}