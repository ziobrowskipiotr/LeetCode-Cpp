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
    void build(TreeNode* root, int*& pointer1, int*& pointer2, vector<int>::iterator begin, vector<int>::iterator end){
        bool f1 = end-begin>1;
        bool h2 = pointer1 != pointer2;
        auto i = find(begin, end, *pointer1);
        if(end-begin>1 && pointer1 != pointer2){
            auto find1 = find(begin, end, *(pointer1 + 1));
            if(find1 != end && i > find1){
                root->left = new TreeNode(*(++pointer1));
                build(root->left, pointer1, pointer2, begin, i);
            }
        }
        bool f = end-begin>1;
        bool h = pointer1 != pointer2;
        if(end-begin>1 && pointer1 != pointer2){
            auto find1 = find(begin, end, *(pointer1 + 1));
            if(find1 != end && i < find1){
                root->right = new TreeNode(*(++pointer1));
                build(root->right, pointer1, pointer2, i+1, end);
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int* pointer1 = &preorder.front();
        int* pointer2 = &preorder.back();
        TreeNode* root = new TreeNode(*pointer1);
        build(root, pointer1, pointer2, inorder.begin(), inorder.end());
        return root;
    }
};