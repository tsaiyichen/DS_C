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
    void preorder_traversal(treenode_t *root);
    TreeNode* copyTree(treenode_t *root);
    bool isEqual(treenode_t *s, treenode_t *t);
    int countTotalNodes(treenode_t *root);
    int countLeafNodes(treenode_t *root);
    int countDegree1Nodes(treenode_t* root);
    int countDegree2Nodes(treenode_t *root);
public:
    BinaryTree();
    BinaryTree(string arr[], int size);
    BinaryTree(BinaryTree &bt);
    TreeNode* getRoot();
    void inorder_traversal();
    void postorder_traversal();
    void preorder_traversal();
    bool isEqual(BinaryTree &bt);
    int countTotalNodes();
    int countLeafNodes();
    int countDegree1Nodes();
    int countDegree2Nodes();
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

TreeNode *BinaryTree::getRoot() {
    return this->root;
}

TreeNode* BinaryTree::copyTree(treenode_t *root) {
    if(root == NULL){
        return nullptr;
    }else{
        treenode_t* temp = new TreeNode(root->data);
        temp->lchild = copyTree(root->lchild);
        temp->rchild = copyTree(root->rchild);
        return temp;
    }
}

BinaryTree::BinaryTree(BinaryTree &bt) {
    this->root = copyTree(bt.getRoot());
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

void BinaryTree::preorder_traversal(treenode_t *root) {
    if(root == NULL){
        return;
    }else{
        cout << root->data;
        preorder_traversal(root->lchild);
        preorder_traversal(root->rchild);
    }
}

bool BinaryTree::isEqual(treenode_t *s, treenode_t *t) {
    bool res = false;
    if(s == NULL && t == NULL){
        res = true;
    }else if(s != NULL && t != NULL){
        if(s->data == t->data){
            if(isEqual(s->lchild, t->lchild)){
                if(isEqual(s->rchild, t->rchild)){
                    res = true;
                }
            }
        }
    }
    return res;
}

int BinaryTree::countTotalNodes(treenode_t *root) {
    if(root == NULL) return 0;
    return countTotalNodes(root->lchild) + countTotalNodes(root->rchild) + 1;
}
int BinaryTree::countLeafNodes(treenode_t* root) {
    if(root == NULL) return 0;
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }else{
        return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
    }
}

int BinaryTree::countDegree1Nodes(treenode_t* root) {
    if(root == NULL) return 0;
    if(root->lchild && !(root->rchild)){
        return countDegree1Nodes(root->lchild) + 1;
    }else if(!(root->lchild) && root->rchild){
        return countDegree1Nodes(root->rchild) + 1;
    }else{
        return countDegree1Nodes(root->lchild) + countDegree1Nodes(root->rchild);
    }
}

int BinaryTree::countDegree1Nodes() {
    return countDegree1Nodes(this->root);
}
int BinaryTree::countLeafNodes() {
    return countLeafNodes(this->root);
}
int BinaryTree::countTotalNodes() {
    return countTotalNodes(this->root);
}
bool BinaryTree::isEqual(BinaryTree &bt) {
    return isEqual(this->root, bt.getRoot());
}
void BinaryTree::preorder_traversal() {
    preorder_traversal(this->root);
    cout << endl;
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
    string bt1Arr[10] = {"A", "B", "C", "D", "E", "", "G", "", "", "H"};
    int arrayLength = sizeof(bt1Arr) / sizeof(bt1Arr[0]);
    BinaryTree bt1(bt1Arr, arrayLength);
    cout << "BT1: " << endl;
    bt1.inorder_traversal();
    bt1.postorder_traversal();
    bt1.preorder_traversal();
    BinaryTree bt2(bt1);
    cout << "BT2: " << endl;
    bt2.inorder_traversal();
    bt2.postorder_traversal();
    bt2.preorder_traversal();
    cout << "BT1 vs BT2: " <<  bt1.isEqual(bt2) << " (same: 1, different: 0)" << endl;
    cout << "the number of total nodes of BT1: " << bt1.countTotalNodes() << endl;
    cout << "the number of total \"leaf\" nodes of BT1: " << bt1.countLeafNodes() << endl;
    cout << "the number of total \"degree-1\" nodes of BT1: " << bt1.countDegree1Nodes() << endl;


}
