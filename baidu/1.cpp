#include<iostream>
using namespace std;

void show() {
  cout << "show" << endl;
}

class A {
  public:
  void show() {
    cout << "A show" << endl;
  }
};

typedef void (*pFunc)();

int main() {
  pFunc p;
  void *v;
  v = (void*)&show;
  p = (pFunc)v;
  p();
  v = (void*)&A::show;
  p = (pFunc)v;
  p();

}