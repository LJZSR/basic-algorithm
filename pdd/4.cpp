#include <iostream>

using namespace std;

int R, G;

int solve1(int R, int G, int i) {
  if (R < i && G < i) return 0;
  int result1 = 0;
  int result2 = 0;
  if (R >= i) result1 = solve1(R-i, G, i+1) + 1;
  if (G >= i) result2 = solve1(R, G-i, i+1) + 1;
  return result1 > result2 ? result1 : result2;
} 

int solve2(int R, int G, int height) {
  if (height == 1) {
    if (R == 1 && G == 1) return 2;
    else return 1;
  }
  int result1 = 0;
  int result2 = 0;
  if (R >= height) result1 = solve2(R-height, G, height-1);
  if (G >= height) result2 = solve2(R, G-height, height-1);
  return (result1+result2) % 1000000007;
}

int main() {
  cin >> R >> G;
  int height = solve1(R, G, 1);
  int ans = solve2(R, G, height);
  cout << ans << endl;
  return 0;
}