class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //#1. Time : O(nlogn), space : O(1), 28ms
        // sort(nums.begin(),nums.end());
        // return nums.at(nums.size()/2);
        
        
        //#2. Using Hashmap
        // 32ms,latest algoritm but memory is good
        unordered_map<int, int> hash; 
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++)
            if (++hash[nums[i]] > n / 2)
                res = nums[i];
                return res;
        
        return res;
        
        
        //#3. More voting algorithm, T:20ms
        // int major, counts = 0, n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     if (!counts) {
        //         major = nums[i];
        //         counts = 1;
        //     }
        //     else counts += (nums[i] == major) ? 1 : -1;
        // }
        // return major;
    }
};
