#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL);

int mp,mf,ms,mv,n;
int v[17][17];
vector<pair<int, vector<int> > > ans;
vector<int> indxlist;
int cnt = 0;

void dfs(int index, vector<int> elm){
    vector<int> tmp = elm;

    if(index > n+1){
        return ;
    }

    if(elm[0] >= mp && elm[1] >= mf && elm[2] >= ms && elm[3] >= mv){
        // cout<<"total:"<<elm[4]<<", indies: ";
        // for(int i = 0; i < indxlist.size(); i++){
        //     cout<<indxlist[i]<<" ";
        // }cout<<"\n";
        ans.push_back({elm[4], indxlist});
    }

    for(int i = 0; i < 5; i++){
        tmp[i] += v[index][i];
    }

    indxlist.push_back(index);

    dfs(index+1, tmp);
    indxlist.pop_back();
    dfs(index+1, elm);
    
}

int main(){
    FAST_IO
    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 5; j++)
        cin>>v[i][j];
    }

    vector<int> s(5,0);

    dfs(1,s);
    
    sort(ans.begin(), ans.end());

    if(ans.size()<1){
        cout<<-1;
    }else{
        cout<<ans[0].first<<"\n";
        for(int i = 0; i < ans[0].second.size(); i++){
            cout<<ans[0].second[i]<<" ";
        }
    }

    return 0;
}