#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> pque;

  pque.push(3);
  pque.push(5);
  pque.push(1);

  while (!pque.empty())
  {
    cout << pque.top() << " ";
    pque.pop();
  }
  cout << endl;
  return 0;
}