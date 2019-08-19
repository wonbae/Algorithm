class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        bool check[26] = {0,};
        int res = 0;
        bool flag = 0;
        for(int i : chars){
            check[i - 'a'] = 1;
        }
        
        for(int i = 0; i < words.size(); i++){
            // cout<<"words.size() : "<<words[i].size()<<endl;
            for(int j = 0 ; j <  words[i].size(); j++){
                for(int k = 0; k < 26; k++){
                    if(check[k] == words[i][j]){
                        flag=true;
                    }else{
                        flag=false;
                    }
                }
            }
            if(flag){
                res += words.size();
            }
        }
        
        
        return res;
    }
    
};
