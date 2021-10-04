#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};
struct BST
{
    Node* root = NULL;
    void add(Node* node, int x){
        if (node->val == x) return;
        if (node->val > x){
            if (node->left == NULL){
                node->left = new Node(x);
                return;
            }
            add(node->left, x);
            return;
        }
        if (node->right == NULL){
            node->right = new Node(x);
            return;
        }
        add(node->right, x);
    }
    void add(int x){
        if (root == NULL){
            root = new Node(x);
            return;
        }
        add(root, x);
    }
    int height(){
        return height(root);
    }
    int height(Node* node){
        if (node == NULL) return 0;
        int l = height(node->left);
        int r = height(node->right);
        return max(l, r) + 1;
    }
    int count(){
        return count(root);
    }
    int count(Node* node){
        if (node == NULL) return 0;
        int l = count(node->left);
        int r = count(node->right);
        return l+r+1;
    }
    void print(){
        print(root);
    }
    void print(Node* node){
        if (node == NULL) return;
        print(node->left);
        cout<<node->val<<"\n";
        print(node->right);
    }
};


int main(){
    BST bst = new BST();
    int n; cin >> n;
    while (n != 0)
    {
        bst.add(n);
        cin>>n;
    }
    cout<<bst.height()<<"\n";
    cout<<bst.cnt()<<"\n";
    bst.print();
    return 0;
}