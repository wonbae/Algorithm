class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //#1. Using Sorting
//         vector<int> arr = nums;
//         sort(arr.begin(),arr.end());
//         int start = arr.size(), end = 0;
        
//         for(int i = 0; i < arr.size(); i++){
//             if(arr[i] != nums[i]){
//                 start = min(start, i);
//                 end = max(end, i);
//             }
//         }
        
//         return (end - start >= 0 ? end - start +1 : 0);
        
        //#2. Using Stack
        stack<int> st;
        int l = nums.size(), r = 0;
        int tmp;
        
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                tmp = st.top();
                l = min(l,tmp);
                st.pop();
            }
                
            st.push(i);
        }
        
        while(!st.empty())  st.pop();
        
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                tmp = st.top();
                r = max(r, tmp);
                st.pop();
            }
                
            st.push(i);
        }

        return r - l > 0 ? r - l + 1 : 0;
 
    }
};
