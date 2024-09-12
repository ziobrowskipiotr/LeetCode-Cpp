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
    void build(TreeNode* root, unordered_map<int, int> &in_map, int* &pointer, int* &pointer_start, int start, int end){
        if(pointer>pointer_start && (in_map[*(pointer-1)] >= start && in_map[*(pointer-1)] <= end)){
            if(in_map[*(pointer-1)]>in_map[*pointer]){
                pointer--;
                root->right = new TreeNode(*pointer);
                build(root->right, in_map, pointer, pointer_start, in_map[*(pointer+1)]+1, end);
            }
        }
        if(pointer>pointer_start && (in_map[*(pointer-1)] >= start && in_map[*(pointer-1)] <= end)){
            if(in_map[*(pointer-1)]<in_map[*pointer]){
                pointer--;
                root->left = new TreeNode(*pointer);
                build(root->left, in_map, pointer, pointer_start, start, in_map[*(pointer+1)]-1);
            }
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int* pointer = &postorder.back();
        int* pointer_start = &postorder[0];
        int start = 0;
        int end = inorder.size()-1;
        TreeNode* root = new TreeNode(*pointer);
        unordered_map<int, int> in_map;
        for(int i=0; i<=end; i++){
            in_map[inorder[i]] = i;
        }
        build(root, in_map, pointer, pointer_start, start, end);
        return root;
    }
};