class Solution {
public:
    void reverseString(vector<char>& s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int right = s.size()-1;
        int left = 0;
        char tmp;
        
        while(left < right){
            // swap(s[left], s[right]);
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        
    }
};
