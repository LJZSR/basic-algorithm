#include<iostream>
#include<string>

using namespace std;

const int MAX_LEN = 1000;

void ReplaceBlank(char str[], int length) {
  if (!str || length <=0) {
    return;
  }
  int spaceNum = 0;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ') {
      spaceNum++;
    }
    ++i;
  }
  int p1 = length + 2 * spaceNum;
  int p2 = length - 1;
  str[p1] = '\0';
  --p1;
  while (p1 != p2) {
    if (str[p2] == ' ') {
      str[p1] = '0';
      p1--;
      str[p1] = '2';
      p1--;
      str[p1] = '%';
      p1--;
      p2--;
    } else {
      str[p1] = str[p2];
      p1--;
      p2--;
    }
  }
}

int main() {
  char str[MAX_LEN];
  string s;
  getline(cin, s);
  int len = 0;
  while (len < s.length()) {
    str[len] = s[len];
    ++len;
  }
  str[len] = '\0';
  ReplaceBlank(str, len);
  cout << str << endl;
  return 0;
}