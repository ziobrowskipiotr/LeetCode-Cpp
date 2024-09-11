/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* root = new TreeNode();
    void build(TreeNode* root, vector<int>& preorder, vector<int>& inorder) {
        auto i = find(inorder.begin(), inorder.end(), preorder.at(0));
        if(inorder.size()>1 && preorder.size()>1 && find(inorder.begin(), inorder.end(), preorder.at(1)) != inorder.end() && i-inorder.begin() > find(inorder.begin(), inorder.end(), preorder.at(1))-inorder.begin()){
            preorder.erase(preorder.begin());
            root->left = new TreeNode(preorder.at(0));
            vector<int> lsub_inorder(inorder.begin(), i);
            build(root->left, preorder, lsub_inorder);
        }
        if(inorder.size()>1 && preorder.size()>1 && find(inorder.begin(), inorder.end(), preorder.at(1)) != inorder.end() && i-inorder.begin() < find(inorder.begin(), inorder.end(), preorder.at(1))-inorder.begin()){
            preorder.erase(preorder.begin());
            root->right = new TreeNode(preorder.at(0));
            vector<int> rsub_inorder(i+1, inorder.end());   
            build(root->right, preorder, rsub_inorder);
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root->val = preorder.at(0);
        build(root, preorder, inorder);
        return root;
    }
};