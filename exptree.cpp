/*
Construct an expression tree from the given prefix expression eg. +--a*bc/def and
traverse it using post order traversal (non recursive) and then delete the entire tree.
*/
#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
public:
    char val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char value)
	{
		val=value; 
		left=NULL; 
		right=NULL;
	}
};

class ExpressionTree {
private:
    TreeNode* root;
    
    void deleteTree(TreeNode* node) {
        if (!node) return;
        
        deleteTree(node->left);
        deleteTree(node->right);
        
        delete node;
    }
    
public:
    ExpressionTree()
	{
    	root=NULL;
	}
    
    void constructFromPrefix(const string& prefixExpr) {
        stack<TreeNode*> stk;
        
        for (int i = prefixExpr.size() - 1; i >= 0; i--) {
            char ch = prefixExpr[i];
            
            if (isalnum(ch)) {
            	/*isalnum() is a C++ function from the <cctype> 
				library that checks whether a given character is alphanumeric 
				(either a letter or a digit).*/
                TreeNode* node = new TreeNode(ch);
                stk.push(node);
            } else {
                TreeNode* node = new TreeNode(ch);
                node->left = stk.top();
                stk.pop();
                node->right = stk.top();
                stk.pop();
                stk.push(node);
            }
        }
        
        root = stk.top();
        //return root;
    }
    
    void postorderTraversal() {
        if (!root) return;
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } 
			else {
                TreeNode* topNode = stk.top();
                
                if (topNode->right && topNode->right != prev) {
                    curr = topNode->right;
                } else {
                    cout << topNode->val << " ";
                    stk.pop();
                    prev = topNode;
                }
            }
        }
    }
    
    void deleteTree() {
        deleteTree(root);
        root = NULL;
    }

};

int main() {
    string prefixExpr = "+--a*bc/def";
    
    ExpressionTree tree;
    
    // Construct expression tree
    tree.constructFromPrefix(prefixExpr);

    cout << "Postorder traversal: ";
    tree.postorderTraversal();
    cout << endl;

    tree.deleteTree();
    
    return 0;
}
