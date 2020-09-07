#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
const int MAX_N = 24;

int main() {
  while (true) {
    cin >> n;
    bool res = true;
    vector<int> a;
    vector<int> leaf;
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
      leaf.push_back(0);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        for (int j = 0; j < n; ++j) {
          if (a[j] != 1) {
            --a[j];
            leaf[j] += leaf[i] + 1; 
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] != 1 || leaf[i] == 1) {
        res = false;
        break;
      } 
    }
    if (res) {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
    
  }
}