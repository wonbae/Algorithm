class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // #1
        // for (int i = 2; i < A.size(); ++i)
        //     if (A[i] == A[i - 1] || A[i] == A[i - 2])
        //         return A[i];
        // return A[0];
        
        // #2
        unordered_set<int> seen;
        for(int x : A){            
            if(seen.count(x)){
                return x;
            }
            seen.insert(x);
            
        }
        return 0;
    }
    
    
    
};
