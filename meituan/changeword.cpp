#include<iostream>
#include<string>

using namespace std;


string article;
int main() {
  cin >> article;
  int lower = 0;
  int higher = 0;
  for (int i =0; i < article.length(); ++i) {
    if (article[i] >= 'a' && article[i] <= 'z') {
      lower++;
    }
    if (article[i] >= 'A' && article[i] <= 'Z') {
      higher++;
    }
  }
  if (lower > higher) {
    cout << (lower - higher) / 2 << endl;
  }
  else
  {
    cout << (higher - lower) / 2 << endl; 
  }
  
}