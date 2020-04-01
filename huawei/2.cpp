#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int> myMap;
vector<string> tmp;
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    if (myMap.find(str) != myMap.end()) {
      myMap[str]++;
    }
    else
    {
      myMap[str] = 1;
      tmp.push_back(str);
    }
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < tmp.size(); ++i) {
    cout << tmp[i] << " " << myMap[tmp[i]] << endl;
  }
  return 0;
}
 