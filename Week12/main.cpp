# if 0
#include <iostream>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode *left;
    TreeNode *right;
    
    // Constructor function
    TreeNode(char value, TreeNode *llink, TreeNode *rlink) {
        data = value;
        left = llink;
        right = rlink;
    }
};

// Inorder Traversal Function
void inorder(TreeNode* root) {
    if (root == NULL) return;   // ⭐️
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

// Preorder Traversal Function
void preorder(TreeNode* root) {
    if (root == NULL) return;   // ⭐️
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal Function
void postorder(TreeNode* root) {
    if (root == NULL) return;   // ⭐️
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

TreeNode *n1, *n2,*n3, *n4, *n5, *n6, *n7;
TreeNode *root;

int main() {
/*
    // Defining nodes one by one without using a constructor function
    n1 = new TreeNode;
    n1 -> data = '3';
    n1 -> left = NULL; n1 -> right = NULL;
    
    n2 = new TreeNode;
    n2 -> data = '2';
    n1 -> left = NULL; n1 -> right = NULL;
    
    n3 = new TreeNode;
    n3 -> data = '*';
    n3 -> left = n1; n3 -> right = n2;
    
    n4 = new TreeNode;
    n4 -> data = '5';
    n1 -> left = NULL; n1 -> right = NULL;
    
    
    n5 = new TreeNode;
    n5 -> data = '6';
    n5 -> left = NULL; n5 -> right = NULL;
    
    n6 = new TreeNode;
    n6 -> data = '*';
    n6 -> left = n4; n6 -> right = n5;
    
    
    n7 = new TreeNode;
    n7 -> data = '+';
    n7 -> left = n3; n7 -> right = n6;
    
    root = n7;
*/
    
    // Defining nodes easily using a constructor function
    n1 = new TreeNode('3', NULL, NULL);
    n2 = new TreeNode('4', NULL, NULL);
    n3 = new TreeNode('*', n1, n2);
    n4 = new TreeNode('5', NULL, NULL);
    n5 = new TreeNode('6', NULL, NULL);
    n6 = new TreeNode('*', n4, n5);
    n7 = new TreeNode('+', n3, n6);
    root = n7;
        
    // Print postorder traversal
    postorder(root);
    cout << endl;
    
    return 0;
}
#endif
