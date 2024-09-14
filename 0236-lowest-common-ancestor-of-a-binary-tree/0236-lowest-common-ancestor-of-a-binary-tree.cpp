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
        TreeNode* temp1;
        TreeNode* temp2;
        if(root->left != nullptr){
            temp1 = lowestCommonAncestor(root->left, p, q);
        }
        if(root->left == nullptr){
            temp1 = nullptr;
        }
        if(root->right != nullptr){
            temp2 = lowestCommonAncestor(root->right, p, q);
        }
        if(root->right == nullptr){
            temp2 = nullptr;
        }

        if(temp1 != nullptr && temp2 != nullptr){
            return root;
        }
        else if(temp1 == nullptr){
            return temp2;
        }
        else{
            return temp1;
        }
    }
};