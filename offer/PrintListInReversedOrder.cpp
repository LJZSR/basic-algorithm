#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};

void PrintListReversingly_Iteratively(ListNode *head) {
  stack<ListNode*> s;
  ListNode *p = head;
  while (p)
  {
    s.push(p);
    p = p->next;
  }
  while (!s.empty())
  {
    cout << s.top()->val << " ";
    s.pop();
  }
  cout << endl;
}

int main() {
  int len;
  cin >> len;
  ListNode *head;
  if (len == 0) {
    head = NULL;
  } else {
    int tmp;
    cin >> tmp;
    head = new ListNode();
    head->val = tmp;
    ListNode *p = head;
    for (int i=1; i < len; ++i) {
      cin >> tmp;
      p ->next = new ListNode();
      p = p ->next;
      p->val = tmp;
    } 
  }
  PrintListReversingly_Iteratively(head);
  return 0;
}