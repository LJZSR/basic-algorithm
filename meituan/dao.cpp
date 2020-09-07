#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct listNode {
  listNode *pre;
  listNode *next;
  long long val;
};

map<long long, listNode*> seat;
int n;

int main() {
  cin >> n;
  listNode *res = new listNode();
  res->next = NULL;
  res->pre = NULL;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    if (seat.find(a) == seat.end()) {
      listNode *tmp = new listNode();
      if (res->next) {
        listNode *p = seat[res->next->val];
        p->pre = tmp;
      }
      tmp->next = res->next;
      tmp->pre = res;
      tmp->val = a;
      res->next = tmp;
      seat[a] = tmp;
    }
    else {
      listNode *tmp = seat[a];
      tmp->pre->next = tmp->next;
      if (tmp->next) {
        tmp->next->pre = tmp->pre;
      }
      tmp->next = res->next;
      tmp->pre = res;
      res->next = tmp;
    }
  }
  listNode *p = res;
  while (p->next != NULL) {
    cout << p->next->val << endl;
    p = p -> next;
  }
}
