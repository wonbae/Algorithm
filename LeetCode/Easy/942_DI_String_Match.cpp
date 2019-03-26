class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> A;
        int n = S.size();
        for(int i=0,j=0;i<S.size();i++)
        {
            if(S[i]=='I') 
            {
                A.push_back(j);
                j++;
            }
            else if(S[i]=='D') 
            {
                A.push_back(n);
                n--;
            }
            //add last number
            if(i==S.size()-1&&S[i]=='I')  A.push_back(n);
            if(i==S.size()-1&&S[i]=='D')  A.push_back(j);            
        }
         
        return A;
    }
};
