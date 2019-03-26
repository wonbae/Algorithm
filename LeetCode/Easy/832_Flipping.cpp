class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        
        res = A;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                res[i][A.size()-j-1] = A[i][j];
            }
        }
        
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                if(res[i][j] == 1){
                    res[i][j] = 0;
                }else{
                    res[i][j] = 1;
                }
            }
        }
        
        return res;
    }
};
