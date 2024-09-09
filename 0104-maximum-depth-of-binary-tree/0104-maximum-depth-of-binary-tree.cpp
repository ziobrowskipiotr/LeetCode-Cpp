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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        std::queue<pair<TreeNode*, int>> kolejka;
        int k = 1;
        kolejka.push(std::pair(root, k));
        while(!kolejka.empty()){
            if(kolejka.front().first->left != nullptr){
                k = kolejka.front().second+1;
                kolejka.push(std::pair(kolejka.front().first->left, k));
            }
            if(kolejka.front().first->right != nullptr){
                k = kolejka.front().second+1;
                kolejka.push(std::pair(kolejka.front().first->right, k));
            }
            kolejka.pop();
            
        }
        return k;
    }
};