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
    int sum = 0;
    void dfs(TreeNode* root, int L, int R){
        if (!root) return ;
        
        if (L <= root->val && root->val <= R) {
            sum += root->val;
        }
        if (L < root->val) {
            dfs(root->left, L, R);
        }
        if (R > root->val) {
            dfs(root->right, L, R);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return sum;
    }
};
