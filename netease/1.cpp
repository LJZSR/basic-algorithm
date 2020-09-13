#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct treeNode {
  int id;
  treeNode *left;
  treeNode *right;
};

int m, n;
vector<treeNode*> roots;

int pastOrder(treeNode *root) {
  if (!root) {
    return 0;
  }
  int ans = pastOrder(root->left) + pastOrder(root->right);
  if (root->left && root->right) {
    if (!root->left->left && !root->left->right && !root->right->left && !root->right->right) {
      ans++;
    }
  }
  return ans;
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    treeNode *node = new treeNode();
    node->id = i + 1;
    node->left = NULL;
    node->right = NULL;
    roots.push_back(node);
  }
  for (int i = 0; i < n; ++i) {
    int tmp;
    int child;
    string str;
    cin >> tmp;
    cin >> str;
    cin >> child;
    if (str == "left") {
      roots[tmp-1]->left = roots[child-1];
    }
    else {
      roots[tmp-1]->right = roots[child-1];
    }
  }
  treeNode *root = roots[0];
  int ans = pastOrder(root);
  cout << ans << endl;
  return 0;
}