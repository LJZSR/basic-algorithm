#include <iostream>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e12;
const ll MAX_L = 1e6;
const ll MAX_SQRT_B = 1e6;

bool is_prime[MAX_L];
bool is_prime_min[MAX_SQRT_B];

ll a, b;

int solve(ll a, ll b) {
  for (ll i = 0; i * i <= b; ++i) {
    is_prime_min[i] = true;
  }
  for (ll i = 0; i < b-a; ++i) {
    is_prime[i] = true;
  }
  for (ll i = 2; i*i < b; ++i) {
    if (is_prime_min[i]) {
      for (ll j = 2*i; j*j < b; j += i) {
        is_prime_min[j] = false;
      }
      for (ll j = (a/i+1)*i; j < b; j += i) {
        is_prime[j-a] = false;
      }
    }
  }
}

int main(){
  cin >> a >> b;
  int ans = solve(a, b);
  cout << ans << endl;
  return 0;
}

