#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<int, string> a;
  a.insert(make_pair(1, "one"));
  a.insert(make_pair(10, "ten"));
  a[100] = "hundred";

  map<int, string>::iterator ite;

  ite = a.find(1);
  if (ite == a.end()) cout << "Not Found!" << endl;
  else cout << ite->second << endl;

  ite = a.find(2);
  if (ite == a.end()) cout << "Not Found!" << endl;
  else cout << ite->second << endl;

  cout << a[10] << endl;

  a.erase(10);

  for (ite = a.begin(); ite != a.end(); ++ite) {
    cout << ite->first << " : " << ite->second << endl;
  }
  return 0;
}