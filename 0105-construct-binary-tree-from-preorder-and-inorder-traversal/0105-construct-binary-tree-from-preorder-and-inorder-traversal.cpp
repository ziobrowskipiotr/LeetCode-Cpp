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
    void complete_tree(TreeNode* &root, unordered_map<int, int*> &in_map, int* &pointer, int* &end_pointer, int* start, int* end){
        if(pointer != end_pointer && (in_map[*(pointer+1)]>=start && in_map[*(pointer+1)]<=end)){
            if(in_map[*(pointer+1)] < in_map[*pointer]){
                root->left = new TreeNode(*(pointer+1));
                complete_tree(root->left, in_map, ++pointer, end_pointer, start, in_map[*(pointer-1)]-1);
            }
        }
        if(pointer != end_pointer && (in_map[*(pointer+1)]>=start && in_map[*(pointer+1)]<=end)){
            if(in_map[*(pointer+1)] > in_map[*pointer]){
                root->right = new TreeNode(*(pointer+1));
                complete_tree(root->right, in_map, ++pointer, end_pointer, (in_map[*(pointer-1)]+1), end);
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int* pointer = &preorder.front();
        int* end_pointer = &preorder.back();
        int* start = &inorder.front();
        int* end = &inorder.back();
        TreeNode* root = new TreeNode(*pointer);
        unordered_map<int, int*> in_map;
        for(int i=0; i<inorder.size(); i++){
            in_map[inorder[i]] = &inorder[i];
        }
        complete_tree(root, in_map, pointer, end_pointer, start, end);
        return root;
    }
};