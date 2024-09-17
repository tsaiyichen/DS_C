#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
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
protected:
    TreeNode* root;
    void inorder_traversal(treenode_t *root);
    void postorder_traversal(treenode_t *root);
    void preorder_traversal(treenode_t *root);
    void levelorder_traversal(treenode_t *root);
    TreeNode* copyTree(treenode_t *root);
    bool isEqual(treenode_t *s, treenode_t *t);
    int countTotalNodes(treenode_t *root);
    int countLeafNodes(treenode_t *root);
    int countDegree1Nodes(treenode_t* root);
    int countDegree2Nodes(treenode_t *root);
    int countHeight(treenode_t* root);
    void swapTree(treenode_t* root);
    double expressionEvaluation(treenode_t* root);
    double op(double x1, double x2, string op);
public:
    BinaryTree();
    BinaryTree(string arr[], int size);
    BinaryTree(BinaryTree &bt);
    TreeNode* getRoot();
    void inorder_traversal();
    void postorder_traversal();
    void preorder_traversal();
    void levelorder_traversal();
    bool isEqual(BinaryTree &bt);
    int countTotalNodes();
    int countLeafNodes();
    int countDegree1Nodes();
    int countDegree2Nodes();
    int countHeight();
    void swapTree();
    double expressionEvaluation();
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
        cout << " " << root->data << " ";
        inorder_traversal(root->rchild);
    }
}

void BinaryTree::postorder_traversal(treenode_t *root) {
   if(root == NULL){
       return;
   }else{
       postorder_traversal(root->lchild);
       postorder_traversal(root->rchild);
       cout << " " << root->data << " ";
   }
}

void BinaryTree::preorder_traversal(treenode_t *root) {
    if(root == NULL){
        return;
    }else{
        cout << " " << root->data << " ";
        preorder_traversal(root->lchild);
        preorder_traversal(root->rchild);
    }
}
void BinaryTree::levelorder_traversal(treenode_t *root){
    if(root == nullptr){
        return;
    }else{
        queue<treenode_t*> q;
        q.push(root);
        while(!q.empty()){
            treenode_t* current = q.front();
            q.pop();
            cout << " " << current->data << " ";
            if(current->lchild) q.push(current->lchild);
            if(current->rchild) q.push(current->rchild);
        }
    }
}
void BinaryTree::levelorder_traversal(){
    levelorder_traversal(this->root);
    cout << endl;
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

int BinaryTree::countDegree2Nodes(treenode_t* root) {
    if(root == NULL) return 0;
    if(root->lchild != NULL && root->rchild != NULL){
        return countDegree2Nodes(root->lchild) + countDegree2Nodes(root->rchild) + 1;
    }else{
        return countDegree2Nodes(root->lchild) + countDegree2Nodes(root->rchild);
    }
}

int BinaryTree::countHeight(treenode_t *root) {
    if(root == NULL) return 0;
    return max(countHeight(root->lchild), countHeight(root->rchild)) + 1;
}

void BinaryTree::swapTree(treenode_t *root) {
    if(root == NULL) return;
    swapTree(root->lchild);
    swapTree(root->rchild);
    treenode_t * temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    return;
}

double BinaryTree::expressionEvaluation(treenode_t* root) {
    if(root == NULL) return 0;
    if(root->lchild == NULL && root->rchild == NULL) //root is operand
        return stod(root->data);
    double x = expressionEvaluation(root->lchild);
    double y = expressionEvaluation(root->rchild);
    return op(x, y, root->data);
}

double BinaryTree::op(double x1, double x2, string op){

    if(op == "+") return x1 + x2;
    if(op == "-") return x1 - x2;
    if(op == "*") return x1 * x2;
    if(op == "/") return x1 / x2;
    if(op == "^") return pow(x1, x2);

    return INT_MIN;
}

double BinaryTree::expressionEvaluation() {
    return expressionEvaluation(this->root);
}
void BinaryTree::swapTree() {
    swapTree(this->root);
    return;
}

int BinaryTree::countHeight(){
    return countHeight(this->root);
}
int BinaryTree::countDegree2Nodes() {
    return countDegree2Nodes(this->root);
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
class BinarySearchTree: public BinaryTree{
public:
    BinarySearchTree(int arr[], int len);
    void insertNode(int x);
    void deleteNode(int x);
    string maxNode();
    string minNode();
    void searchNode(int x);
private:
    treenode_t* insertNode(treenode_t *root, int x);
    treenode_t* deleteNode(treenode_t *root, int x);
    treenode_t* minNode(treenode_t* root);
    treenode_t* maxNode(treenode_t *root);
    bool searchNode(treenode_t *root, int x);
};

treenode_t* BinarySearchTree::insertNode(treenode_t *root, int x) {
    if(root == NULL){
        treenode_t *temp = new TreeNode(to_string(x));
        return temp;
    }
    if(x > stoi(root->data))
        root->rchild = insertNode(root->rchild, x);
    else if(x < stoi(root->data))
        root->lchild = insertNode(root->lchild, x);

    return root;
}

treenode_t *BinarySearchTree::deleteNode(treenode_t *root, int x) {
    if(root == NULL) return NULL;
    if(x > stoi(root->data))
        root->rchild = deleteNode(root->rchild, x);
    else if(x < stoi(root->data))
        root->lchild = deleteNode(root->lchild, x);
    else{
        if(root->lchild == NULL && root->rchild == NULL){
            //root is leaf node
            delete root;
            return NULL;
        }else if(root->lchild != NULL && root->rchild != NULL){
            //root is degree-2 node
            treenode_t* replace = minNode(root->rchild);
            root->data = replace->data;
            root->rchild = deleteNode(root->rchild, stoi(replace->data));
            /*
             * treenode_t* replace = maxNode(root->lchild);
             * root->data = replace->data;
             * root->lchild = deleteNode(root->lchild, stoi(replace->data);
             */
        }else{
            //root is degree-1 node
            treenode_t *temp;
            if(root->lchild) temp = root->lchild;
            else temp = root->rchild;
            delete root;
            return temp;
        }
    }
    return root;
}

string BinarySearchTree::minNode() {
    return minNode(this->root)->data;
}
string BinarySearchTree::maxNode() {
    return maxNode(this->root)->data;
}
void BinarySearchTree::deleteNode(int x) {
    this->root = deleteNode(this->root, x);
}
treenode_t* BinarySearchTree::minNode(treenode_t* root){
    if(root->lchild == NULL) return root;
    else return minNode(root->lchild);
}
treenode_t* BinarySearchTree::maxNode(treenode_t *root) {
    if(root->rchild == NULL) return root;
    else return maxNode(root->rchild);
}
void BinarySearchTree::insertNode(int x) {
    root = insertNode(root, x);
}
BinarySearchTree::BinarySearchTree(int arr[], int len): BinaryTree() {
    for(int i = 0; i < len; i++){
        int current = arr[i];
        insertNode(current);
    }
}

bool BinarySearchTree::searchNode(treenode_t *root, int x) {
    if(root == NULL) return false;
    if(x > stoi(root->data)) return searchNode(root->rchild, x);
    if(x < stoi(root->data)) return searchNode(root->lchild, x);
    return true;
}

void BinarySearchTree::searchNode(int x) {
    if(searchNode(this->root, x)){
        cout << "search for " << x << " is successful." << endl;
    }else{
        cout << "search for " << x << " is unsuccessful." << endl;
    }
}

int main(){
    string bt1Arr[10] = {"A", "B", "C", "D", "E", "", "G", "", "", "H"};
    int arrayLength = sizeof(bt1Arr) / sizeof(bt1Arr[0]);
    BinaryTree bt1(bt1Arr, arrayLength);
    cout << "BT1: " << endl;
    bt1.inorder_traversal();
    bt1.postorder_traversal();
    bt1.preorder_traversal();
    bt1.levelorder_traversal();
    BinaryTree bt2(bt1);
    cout << "BT2: " << endl;
    bt2.inorder_traversal();
    bt2.postorder_traversal();
    bt2.preorder_traversal();
    bt2.levelorder_traversal();
    cout << "BT1 vs BT2: " <<  bt1.isEqual(bt2) << " (same: 1, different: 0)" << endl;
    cout << "the number of total nodes of BT1: " << bt1.countTotalNodes() << endl;
    cout << "the number of total \"leaf\" nodes of BT1: " << bt1.countLeafNodes() << endl;
    cout << "the number of total \"degree-1\" nodes of BT1: " << bt1.countDegree1Nodes() << endl;
    cout << "the number of total \"degree-2\" nodes of BT1: " << bt1.countDegree2Nodes() << endl;
    cout << "this tree height: " << bt1.countHeight() << endl;
    bt1.swapTree();
    cout << "After swap: inorder traversal = ";
    bt1.inorder_traversal();
    cout << "After swap: postorder traversal = ";
    bt1.postorder_traversal();
    string express[11]{"-", "-", "+", "9", "*", "6", "2", "", "", "1", "2"};
    BinaryTree expBT(express, 11);
    expBT.postorder_traversal();
    cout << "evalution result: " << expBT.expressionEvaluation() << endl;
    string express2[15]{"*", "-", "+", "4", "3", "5", "/", "", "", "", "", "", "", "6", "3"};
    BinaryTree expBT2(express2, 15);
    expBT2.postorder_traversal();
    cout << "evalution result: " << expBT2.expressionEvaluation() << endl;

    cout << "-------------------BST-------------------" << endl;
    int bstArr[9] = {10, 33, 15, 8, 4, 5, 6, 26, 40};
    BinarySearchTree bst1(bstArr, 9);
    bst1.inorder_traversal();
    bst1.insertNode(37);
    bst1.inorder_traversal();
    bst1.deleteNode(26);
    bst1.inorder_traversal();
    cout << "max: " << bst1.maxNode() << endl;
    cout << "min: " << bst1.minNode() << endl;
    bst1.searchNode(33);
    bst1.searchNode(54);
}
