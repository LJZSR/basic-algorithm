#include <iostream>

using namespace std;

const int MAX_N = 1000000;

bool is_prime[MAX_N + 1];
int prime[MAX_N + 1];
int p = 0, n = 0;

int sieve(int n) {
  int p = 0;
  for (int i = 0; i < n + 1; ++i) {
    is_prime[i] = true;
  }
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p] = i;
      ++p;
      for (int j = 2 * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return p;
}

int main(){
  cin >> n;
  p = sieve(n);
  for (int i = 0; i < p; ++i) {
    cout << prime[i] << " ";
  }
  cout << endl;
  cout << p << endl;
}