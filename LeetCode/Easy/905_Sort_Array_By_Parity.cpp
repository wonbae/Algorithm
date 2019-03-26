//#28ms, 9.5MB
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> arr;
        int count = 0;
        
        arr = A;
        for(int i = 0; i < A.size(); i++){
            if(A.at(i) % 2 == 0){
                arr[count++] = A.at(i);
            }
        }
        for(int i = 0; i < A.size(); i++){
            if(A.at(i) % 2 != 0){
                arr[count++] = A.at(i);    
            }
        }
        return arr;
        
    }
};
