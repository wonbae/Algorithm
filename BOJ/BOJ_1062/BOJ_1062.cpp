#include<bits/stdc++.h>
using namespace std;

int word[51];
int n,k;
string str;

int count(int mask){
    int cnt = 0;
    for(auto w : word){
        if(w && (w & mask) == w) cnt++;
    }
    return cnt;
}

int solve(int index, int k, int mask){
    if(k<0) return 0;
    if(index==26) return count(mask);

    int ret = solve(index+1, k-1, mask|(1<<index));
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        ret = max(ret, solve(index+1, k, mask));
    }
    
    return ret;
}

int main(){
    cin>>n>>k;
    
    for(int i = 0; i < n; i++){
        cin>>str;
        for(auto s : str){
            word[i] |= (1<<(s-'a'));
        }
    }

    cout<<solve(0, k, 0)<<"\n";

    return 0;
}