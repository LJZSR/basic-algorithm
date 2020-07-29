#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> data;
vector<int> copyD;

void mergesort(vector<int> &data, vector<int> &copy, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int mid = (begin + end) / 2;
  mergesort(data, copy, begin, mid);
  mergesort(data, copy, mid+1, end);
  int i = end;
  int j = mid;
  int k = end;
  while (i > mid && j >= begin) {
    if (data[i] > data[j]) {
      copy[k] = data[i];
      --k;
      --i;
    }
    else {
      copy[k] = data[j];
      --k;
      --j;
    }
  }
  while (i > mid) {
    copy[k] = data[i];
    --k;
    --i;
  }
  while (j >= begin) {
    copy[k] = data[j];
    --k;
    --j;
  }
  for (int index = begin; index <= end; ++index) {
    data[index] = copy[index];
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    data.push_back(in);
    copyD.push_back(in);
  }

  mergesort(data, copyD, 0, n-1);
  for (int i = 0; i < n; ++i) {
    cout << data[i] << " ";
  }
  cout << endl;
}