#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > red;
vector<pair<int, int> > blue;

int N;

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int num, color;
    cin >> num >> color;
    if (color == 1) {
      red.push_back(make_pair(num, i+1));
    }
    else{
      blue.push_back(make_pair(num, i+1));
    }
  }
  if (red.size() < 2 && blue.size() < 2) {
    cout << "null" << endl;
  }
  sort(red.rbegin(), red.rend());
  sort(blue.rbegin(), blue.rend());
  int redRes = 0, blueRes = 0;
  if (red.size() >= 3) {
    redRes = red[0].first + red[1].first + red[2].first;
  }
  if (blue.size() >= 3) {
    blueRes = blue[0].first + blue[1].first + blue[2].first;
  }
  if (redRes > blueRes) {
    cout << red[2].second << " " << red[1].second << " " << red[0].second << endl;
    cout << 1 << endl;
    cout << redRes << endl;
  } else {
    cout << blue[2].second << " " << blue[1].second << " " << blue[0].second << endl;
    cout << 2 << endl;
    cout << blueRes << endl;
  }
}