class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL, *cur = root;
        int SUM = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                SUM += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && SUM == sum) {
                return true;
            }
            if (cur->right && pre != cur->right) {
                cur = cur->right;
            } else {
                pre = cur;
                s.pop();
                SUM -= cur->val;
                cur = NULL;
            }
        }
        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> treestack;
        TreeNode *cur=root,*pre=NULL;
        vector<int> res;
        
        while(!treestack.empty() || cur){
            while(cur){
                treestack.push(cur);
                cur=cur->left;
            }
            cur=treestack.top();
            if(cur->right && cur->right!=pre){
                cur=cur->right;
            }else{
                res.push_back(cur->val);
                pre = cur;
                treestack.pop();
                cur = NULL;
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
        return result;
        nodeStack.push(root);
    while(!nodeStack.empty())
    {
        TreeNode* node= nodeStack.top();  
        result.push_back(node->val);
        nodeStack.pop();
        if(node->left)
        nodeStack.push(node->left);
        if(node->right)
        nodeStack.push(node->right);
    }
     reverse(result.begin(),result.end());
     return result;
    
}
