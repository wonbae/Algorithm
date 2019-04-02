class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), res = 0;
        
        for(int mid = 0; mid <= 2*len-1; mid++){
            int left = mid / 2;
            int right = left + mid % 2;
            while(left >= 0 && right < len && s[left] == s[right]){
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};
