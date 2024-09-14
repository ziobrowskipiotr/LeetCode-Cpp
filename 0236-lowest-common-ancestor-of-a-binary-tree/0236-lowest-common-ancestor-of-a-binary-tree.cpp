/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q){
            return root;
        }
        if(root->left){
            root->left = lowestCommonAncestor(root->left, p, q);
        }
        if(root->right){
            root->right = lowestCommonAncestor(root->right, p, q);
        }
        if(root->left && root->right){
            return root;
        }
        else if(!root->left){
            return root->right;
        }
        else{
            return root->left;
        }
    }
};