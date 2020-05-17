#include <iostream>
#include <vector>

using namespace std;

int T, R, C;

char G[30][30];
int build[30][30];
int building[30][30];

int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    vector<char> ans;
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        cin >> G[r][c];
      }
    }
    
    
  }
  return 0;
}