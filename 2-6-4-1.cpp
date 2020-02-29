#include <iostream>

using namespace std;

typedef long long ll;

int n = 0;

bool is_prime(ll n) {
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

ll mod_pow(ll x, ll n, ll mod) {
  ll ans = 0;
  if (n == 0) ans = 1;
  else {
    ans = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) ans = ans * x % mod;
  }
  return ans;
}

int main(){
  cin >> n;
  bool flag = true;
  for (int i = 2; i < n; ++i) {
    ll ans = mod_pow(i, n, n); 
    if (ans != i % n) {
      flag = false;
    }
  }
  if (flag && !is_prime(n)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}