class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    int counter[26] = {0,};
    for (int i = 0; i < s.length(); i++) {
        counter[s.at(i) - 'a']++;
        counter[t.at(i) - 'a']--;
    }
    
    for(int count = 0; count < 26; count++){
        if(counter[count] != 0){
            return false;
        }
    }
    return true;
    }
};

