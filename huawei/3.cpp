#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> input;
int main() {
  string str;
  string target;
  while (getline(cin, str)) {
    input.push_back(str);

    if (str.find("search") == 0) {
      int index = str.find(":");
      target = str.substr(index+1, str.length()-index);
      break;
    }
  }
  cout << "none loop include " + target << endl;
  return 0;
}