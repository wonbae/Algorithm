#include<bits/stdc++.h>
using namespace std;

void dfs(int n, int m, vector<int>& seq, int prev){
    if(m == 0){
        for(auto e : seq){
            cout<<e<<" ";
        }cout<<"\n";
        
        return ;
    }

    for(int i = prev; i <= n; i++){
        seq.push_back(i);
        dfs(n, m-1, seq, i);
        seq.pop_back();
    }

    return;
}


int main(){
    int n, m;
    cin>>n>>m;

    vector<int> seq;

    dfs(n, m, seq, 1);


    return 0;
}