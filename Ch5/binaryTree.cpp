#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct TreeNode {
    string data;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(string s) : data(s), lchild(nullptr), rchild(nullptr) {}
}treenode_t;

struct q_t {
    TreeNode* node;
    int index;

    q_t(TreeNode* n, int i) : node(n), index(i) {}
};

class BinaryTree {
private:
    TreeNode* root;
    void inorder_traversal(treenode_t *root);
    void postorder_traversal(treenode_t *root);
public:
    BinaryTree();
    BinaryTree(string arr[], int size);
    void inorder_traversal();
    void postorder_traversal();
};

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(string arr[], int size) {
    if (size == 0) {
        root = nullptr;
        return;
    }

    queue<q_t> q;
    root = new TreeNode(arr[0]);
    q.push(q_t(root, 0));

    while (!q.empty()) {
        q_t qtTemp = q.front();
        q.pop();

        TreeNode* current = qtTemp.node;
        int num = qtTemp.index;
        int NL = 2 * num + 1;
        int NR = 2 * (num + 1);

        if (NL < size && !arr[NL].empty()) {
            TreeNode* nodeL = new TreeNode(arr[NL]);
            current->lchild = nodeL;
            q.push(q_t(nodeL, NL));
        }
        if (NR < size && !arr[NR].empty()) {
            TreeNode* nodeR = new TreeNode(arr[NR]);
            current->rchild = nodeR;
            q.push(q_t(nodeR, NR));
        }
    }
}

void BinaryTree::inorder_traversal(treenode_t* root) {
    if(root == NULL){
        return;
    }else{
        inorder_traversal(root->lchild);
        cout << root->data;
        inorder_traversal(root->rchild);
    }
}

void BinaryTree::postorder_traversal(treenode_t *root) {
   if(root == NULL){
       return;
   }else{
       postorder_traversal(root->lchild);
       postorder_traversal(root->rchild);
       cout << root->data;
   }
}
void BinaryTree::inorder_traversal() {
    inorder_traversal(this->root);
    cout << endl;
}
void BinaryTree::postorder_traversal() {
    postorder_traversal(this->root);
    cout << endl;
}


int main(){
    string array[7] = {"A", "B", "C", "", "E", "", "G"};
    BinaryTree bt1(array, 7);
    bt1.inorder_traversal();
    bt1.postorder_traversal();
}
