class Solution {
public:
    int cnt = 0;
    
    void solution(vector<int>& nums, int i, int sum, int s){
        if(i == nums.size()){
            if(sum == s){
                cnt++;
                return ;
            }
            return ;
        }
        solution(nums, i + 1, sum + nums[i], s);
        solution(nums, i + 1, sum - nums[i], s);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        solution(nums, 0, 0, S);
        return cnt;
    }
};
