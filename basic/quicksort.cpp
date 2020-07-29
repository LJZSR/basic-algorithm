#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in;

int findPivot(vector<int> &in, int start, int end) {
  int p = in[start];
  while (start < end) {
    while (start < end && in[end] > p) --end;
    in[start] = in[end];
    while (start < end && in[start] <= p) ++start;
    in[end] = in[start];
  }
  in[start] = p;
  return start;
}

void quicksort(vector<int> &in, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = findPivot(in, start, end);
  quicksort(in, start, pivot-1);
  quicksort(in, pivot+1, end);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    in.push_back(tmp);
  }
  quicksort(in, 0, in.size()-1);
  for (int i = 0; i < in.size(); ++i) {
    cout << in[i] << " ";
  }
  cout << endl;
  return 0;
}


