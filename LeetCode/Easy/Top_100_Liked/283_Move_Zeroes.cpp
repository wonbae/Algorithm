class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int idx = 0;
        
        for(int num : nums){
            if(num == 0){
                count++;
            }
            else{
                nums.at(idx) = num;
                idx++;
            }
        }
        
        idx = nums.size() - count;
        while(idx < nums.size()){
            nums.at(idx) = 0;
            idx++;    
        }
        
        
    }
};
