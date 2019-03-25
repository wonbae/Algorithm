class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i = 0; i < A.size(); i++){
            A.at(i) = A.at(i) * A.at(i);
        }
        sort(A.begin(), A.end());
        return A;
    }
};
