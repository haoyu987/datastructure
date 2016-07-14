class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> rst{root->val},pre=preorderTraversal(root->left),post=preorderTraversal(root->right);
        rst.resize(1+pre.size()+post.size());
        copy(pre.begin(),pre.end(),rst.begin()+1);
        copy(post.begin(),post.end(),rst.begin()+1+pre.size());
        return rst;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStk;
        vector<int> rst;
        while(root || !treeStk.empty()){
            rst.push_back(root->val);
            if(root->right) treeStk.push(root->right);
            if(root->left) root=root->left;
            else if(!treeStk.empty()){
                root = treeStk.top();
                treeStk.pop();
            }
            else root=NULL;
        }
        return rst;
    }
};

class Solution{
public:
vector<int> preorderTraversal(TreeNode* root) {
    vector<int>res;
    stack<TreeNode*>stack;
    if(!root)return res;
    TreeNode * cur;
    
    stack.push(root);
    while(!stack.empty())
    {
        cur=stack.top();
        res.push_back(cur->val);
        stack.pop();
        if(cur->right)stack.push(cur->right);
        if(cur->left)stack.push(cur->left);
    }
    return res;
}
};


/*
java
public List<Integer> preorderTraversal(TreeNode node) {
	List<Integer> list = new LinkedList<Integer>();
	Stack<TreeNode> rights = new Stack<TreeNode>();
	while(node != null) {
		list.add(node.val);
		if (node.right != null) {
			rights.push(node.right);
		}
		node = node.left;
		if (node == null && !rights.isEmpty()) {
			node = rights.pop();
		}
	}
    return list;
}
*/
