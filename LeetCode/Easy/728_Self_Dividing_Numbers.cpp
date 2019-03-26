class Solution {
public:
    bool check(const int num){
        int i = num;
        int remain;
        
        while(i > 0){
            remain = i % 10;
            if((remain == 0) || (num % remain)){
                return false;
            }
            i /= 10;
        }
        return true;
    }
    
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++){
            if(check(i)){
                res.push_back(i);
            }
        }
        
        return res;
        
    }
};
