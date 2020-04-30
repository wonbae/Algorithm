class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        do{
            for(int i = 0; i < nums.size(); i++){
                v.push_back(nums[i]);
            }
            res.push_back(v);
            v.clear();
            
        }while(next_permutation(nums.begin(), nums.end()));
        
        return res;
    }
};