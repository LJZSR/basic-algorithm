#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> x;
vector<int> y;
vector<int> z;

int main() {
  string in;
  cin >> in;
  a.push_back(0);
  b.push_back(0);
  c.push_back(0);
  x.push_back(0);
  y.push_back(0);
  z.push_back(0);
  for (int i = 0; i < in.length(); ++i) {
    if (in[i] == 'a') {
      a.push_back(a[i]+1);
      b.push_back(b[i]);
      c.push_back(c[i]);
      x.push_back(x[i]);
      y.push_back(y[i]);
      z.push_back(z[i]);
      continue;
    }
    if (in[i] == 'b') {
      a.push_back(a[i]);
      b.push_back(b[i]+1);
      c.push_back(c[i]);
      x.push_back(x[i]);
      y.push_back(y[i]);
      z.push_back(z[i]);
      continue;
    }
    if (in[i] == 'c') {
      a.push_back(a[i]);
      b.push_back(b[i]);
      c.push_back(c[i]+1);
      x.push_back(x[i]);
      y.push_back(y[i]);
      z.push_back(z[i]);
      continue;
    }
    if (in[i] == 'x') {
      a.push_back(a[i]);
      b.push_back(b[i]);
      c.push_back(c[i]);
      x.push_back(x[i]+1);
      y.push_back(y[i]);
      z.push_back(z[i]);
      continue;
    }
    if (in[i] == 'y') {
      a.push_back(a[i]);
      b.push_back(b[i]);
      c.push_back(c[i]);
      x.push_back(x[i]);
      y.push_back(y[i]+1);
      z.push_back(z[i]);
      continue;
    }
    if (in[i] == 'z') {
      a.push_back(a[i]);
      b.push_back(b[i]);
      c.push_back(c[i]);
      x.push_back(x[i]);
      y.push_back(y[i]);
      z.push_back(z[i]+1);
      continue;
    }
    a.push_back(a[i]);
    b.push_back(b[i]);
    c.push_back(c[i]);
    x.push_back(x[i]);
    y.push_back(y[i]);
    z.push_back(z[i]);
  }
  int ans = 0;
  for (int i = 0; i < in.length()+1; ++i) {
    for (int j = i+1; j < in.length()+1; ++j) {
      if ((a[j]-a[i])%2==0&&(b[j]-b[i])%2==0&&(c[j]-c[i])%2==0&&(x[j]-x[i])%2==0&&(y[j]-y[i])%2==0&&(z[j]-z[i])%2==0) {
        ans = ans > (j-i) ? ans : (j-i);
      }
    }
  }
  cout << ans << endl;
  return 0;
}