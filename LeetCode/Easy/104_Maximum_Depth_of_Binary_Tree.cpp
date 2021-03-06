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
    int maxDepth(TreeNode* root) {
        //#1. DFS
        // if(root == NULL){
        //     return 0;
        // }else{
        //     return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
        // }
        
        
        //#2. BFS using STACK
//         if(root == NULL)
//         return 0;
    
//     int res = 0;
//     queue<TreeNode *> q;
//     q.push(root);
//     while(!q.empty())
//     {
//         ++ res;
//         for(int i = 0, n = q.size(); i < n; ++ i)
//         {
//             TreeNode *p = q.front();
//             q.pop();
            
//             if(p -> left != NULL)
//                 q.push(p -> left);
//             if(p -> right != NULL)
//                 q.push(p -> right);
//         }
//     }
    
//     return res;
        
        
        // #3
        if(root == nullptr)
            return 0;
        
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        
        return left>right ? left : right;
    }
};

