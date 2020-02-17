#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> a;
  a.insert(1);
  a.insert(3);
  a.insert(5);

  set<int>::iterator ite;

  ite = a.find(1);
  if (ite == a.end()) cout << "Not Found!" << endl;
  else cout << "Found" << endl;

  ite = a.find(2);
  if (ite == a.end()) cout << "Not Found!" << endl;
  else cout << "Found" << endl;

  return 0;
}