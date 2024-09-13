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
    void dfs(vector<TreeNode*> &wektor, TreeNode* &p, bool &bol){
        if(bol && wektor.back()->left == p){
            wektor.push_back(wektor.back()->left);
            bol = false;
        }
        if(bol && wektor.back()->left != nullptr){
            wektor.push_back(wektor.back()->left);
            dfs(wektor, p, bol);
        }
        if(bol && wektor.back()->right == p){
            wektor.push_back(wektor.back()->right);
            bol = false;
        }
        if(bol && wektor.back()->right != nullptr){
            wektor.push_back(wektor.back()->right);
            dfs(wektor, p, bol);
        }
        if(bol){
            wektor.pop_back();
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> wektor_p;
        vector<TreeNode*> wektor_q;
        bool bol_p = true;
        bool bol_q = true;
        wektor_p.push_back(root);
        wektor_q.push_back(root);
        dfs(wektor_p, p, bol_p);
        dfs(wektor_q, q, bol_q);

        for(int i=wektor_p.size()-1; i>=0; i--){
            for(int j=wektor_q.size()-1; j>=0; j--){
                if(wektor_p[i] == wektor_q[j]){
                    return wektor_p[i];
                }
            }
        }
        return root;
    }
};