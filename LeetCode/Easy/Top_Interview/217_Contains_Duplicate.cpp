class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       // sort(nums.begin(), nums.end());
        if(nums.size() == 0){
            return false;  
        }else{
            sort(nums.begin(), nums.end());
        } 
        
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums.at(i) == nums.at(i+1)){
                return true;
            }
        }
        return false;
        
//         //Set of the numbers we've encountered.
//         unordered_set<int> aSet;
        
//         for (auto aNum : nums) {
            
//             //If we've encountered the number already, it's a duplicate.
//              .find() method returns iterator, .end() returns end of iterator            
//             if (aSet.find(aNum) != aSet.end()) { return true; }
            
//             //Add the number to the set.
//             aSet.insert(aNum);
//         }
//         return false;
    }
};
