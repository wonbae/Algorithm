#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int t, n, k;
    cin>>t;

    while(t--){
        cin>>n>>k;

        vector<int> buildTime(n+1);
        vector<vector<int> > buildOrder(n+1);
        vector<int> dp(k+1);
        vector<int> indegree(n+1);
        int target;

        for(int i = 1; i <= n; i++){
            cin>>buildTime[i];
        }


        for(int i = 0; i < k; i++){
            int st, ed;
            cin>>st>>ed;
            buildOrder[st].push_back(ed);
            indegree[ed]++;
        }
        
        cin>>target;

        queue<int> q;
        
        
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        for(int i = 1; i <= n; i++){
            dp[i] = buildTime[i];
        }


        while(!q.empty()){
            int now = q.front();
            q.pop();

            // cout<<"cur: "<<now<<", time: "<<buildTime[now]<<"\n";

            // for(int i = 1; i <= n; i++){
            //     cout<<dp[i]<<" ";
            // }cout<<"\n";

            

            for(auto &next : buildOrder[now]){
                indegree[next]--;

                dp[next] = max(dp[next], dp[now] + buildTime[next]);

                if(indegree[next] == 0){
                    q.push(next);
                }
            }

        }

        cout<<dp[target]<<"\n";
    }
        
    return 0;
}