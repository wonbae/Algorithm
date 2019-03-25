class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        int i,j;
        
        for(i = 0; i < J.length(); i++){
            for(j = 0; j < S.length(); j++){
                if(J.at(i) == S.at(j)){
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
