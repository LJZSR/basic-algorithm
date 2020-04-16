#include <iostream>

using namespace std;
typedef long long ll;
ll a, b, m, x;

int main () {
  cin >> a >> b >> m >> x;
  ll begin = (a * x + b) % m;
  x = begin;
  ll counter = 1;
  while ((a * x + b) % m != begin) {
    ++counter;
    x = (a * x + b) % m;
  } 
  cout << counter << endl;
  return 0;
}