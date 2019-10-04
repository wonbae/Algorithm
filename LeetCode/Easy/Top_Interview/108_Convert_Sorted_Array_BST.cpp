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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		// solution 1
		// DFS recursive solution
		return sortedArrayToBST(nums, 0, nums.size());
	}
	
	 // DFS recursive solution
	 TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
	 {
		 if(start >= end)
			 return NULL;

		 if(end - start == 1)
		 {
			 return new TreeNode(nums[start]);
		 }

		 int mid = (end + start)/2;
		 TreeNode* root = new TreeNode(nums[mid]);

		 // left
		 root->left = sortedArrayToBST(nums, start, mid);

		 // right
		 root->right = sortedArrayToBST(nums, mid+1, end);

		 return root;
	 }
};
