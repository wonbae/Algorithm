class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //#1. Bit operation
        // int res = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     res ^= nums.at(i);
        // }
        // return res;
        
        //#1-1. Bit operation
        int res = 0;
        for(int i : nums){
            res ^= i;
        }
        return res;
        
        // #2. Using HashMap
        // unordered_set<int> s;
        // for(int num : nums)
        // {
        //     if(s.count(num)) //최빈수, 끽해봐야 2
        //         s.erase(num);
        //     else
        //         s.insert(num);
        // }
        // return *s.begin();
    }
};
