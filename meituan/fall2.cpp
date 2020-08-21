#include<iostream>
#include<string>

using namespace std;

int n;

int main() {
  cin >> n;
  string start = "";
  string end = "";
  int count = 0;
  for (int i = 0; i < n; ++i) {
    string tmp1;
    string tmp2;
    if (start == "") {
      cin >> tmp1;
      start = tmp1;
      cin >> tmp2;
      end = tmp2;
    }
    else {
      cin >> tmp1;
      cin >> tmp2;
      if (tmp2 == start) {
        ++count;
        start = "";
        end = "";
      }
      else {
        end = tmp2;
      }
    }
  }
  cout << count << endl;
}