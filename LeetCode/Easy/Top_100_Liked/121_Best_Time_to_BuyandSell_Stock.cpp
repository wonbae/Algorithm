class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int min = INT_MAX;
        int max = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices.at(i) < min){
                min = prices.at(i);
            }
            else if(prices.at(i) - min > max){
                max = prices.at(i) - min;
            }
        }
        return max;
        
        
        
    }
};
