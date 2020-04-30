class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        int sum = 0, size = nums.size();
        for(int i = 0; i < size; i++){
            sum = 0;
            for(int j = 0; j < size; j++){
                if(i != j){
                    if(nums[i] > nums[j]){
                        sum++;
                    }
                }
            }
            v.push_back(sum);
        }
        
        return v;
    }
};