int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        
        function<int(int,int)> calc = [&](int start, int end){
            if (start > end) return 0;
            if (dp[start][end] != -1) return dp[start][end];
            int s = 0;
            for (int i=start; i<=end; i++) {
                int ss = nums[start-1] * nums[i] * nums[end+1] + calc(start, i-1) + calc(i+1, end);
                s = max(ss, s);
            }
            dp[start][end] = s;
            return s;
        };
        
        return calc(1, nums.size()-2); 
    }
