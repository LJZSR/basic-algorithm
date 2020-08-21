#include <iostream>
#include <vector>

using namespace std;

struct treeNode
{
  treeNode *left;
  treeNode *right;
  int val;
};

int n;
vector<int> preOrder;
vector<int> inOrder;

treeNode* createTree(vector<int> pre, vector<int> in) {
  treeNode *root;
  if (pre.size() == 0) {
    return NULL;
  } 
  int val = pre[0];
  root = new treeNode();
  root->val = val;
  int i = 0;
  while (i < pre.size() && in[i] != val) {
    ++i;
  }
  vector<int> lPreOrder;
  vector<int> lInOrder;
  
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    preOrder.push_back(in);
  }
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    inOrder.push_back(in);
  }
  treeNode *root;
  root = createTree(preOrder, inOrder);
}