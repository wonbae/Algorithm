#include<bits/stdc++.h>
using namespace std;
#define SIZE 16

int N;
int t[SIZE], p[SIZE];
int ans;

void dfs(int day, int profit){
    if(day == N + 1){
        if(ans < profit) ans = profit;
        return ;
    }

    if(day > N + 1) return ;

    dfs(day + t[day], profit + p[day]);
    dfs(day + 1, profit);
}

int main(){
    cin>>N;

    for(int i = 1; i <= N; ++i){
        cin>>t[i]>>p[i];
    }

    dfs(1, 0);

    cout<<ans<<"\n";
    return 0;
}