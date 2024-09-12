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
    void build(TreeNode* root, vector<int>& preorder, vector<int>::iterator begin, vector<int>::iterator end) {
        auto i = find(begin, end, preorder.front());
        if(end-begin>1 && preorder.size()>1){
            auto find1 = find(begin, end, preorder.at(1));
            if(find1 != end && i > find1){
                preorder.erase(preorder.begin());
                root->left = new TreeNode(preorder.front());
                build(root->left, preorder, begin, i);
            }
        }
        if(end-begin>1 && preorder.size()>1){
            auto find1 = find(begin, end, preorder.at(1));
            if(find1 != end && i < find1){
                preorder.erase(preorder.begin());
                root->right = new TreeNode(preorder.front());
                build(root->right, preorder, i+1, end);
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder.front());
        build(root, preorder, inorder.begin(), inorder.end());
        return root;
    }
};