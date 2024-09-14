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
        if(root->left){
            temp1 = lowestCommonAncestor(root->left, p, q);
        }
        else{
            temp1 = nullptr;
        }
        if(root->right){
            temp2 = lowestCommonAncestor(root->right, p, q);
        }
        else{
            temp2 = nullptr;
        }

        if(temp1 && temp2){
            return root;
        }
        else if(!temp1){
            return temp2;
        }
        else{
            return temp1;
        }
    }
};