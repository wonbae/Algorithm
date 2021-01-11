#include<iostream>
using namespace std;

int N, M;
int num[100];
int sum = 0;
int ans;
bool check[100];

inline int max(int a, int b) {return a > b ? a : b;}

void dfs(int idx, int cnt){
    if(cnt == 3){
        if(sum <= M){
            ans = max(ans, sum);
        }
        return ;
    }

    for(int i = idx; i < N; ++i){
        if(check[i]) continue;

        sum += num[i];
        check[i] = true;
        dfs(idx + 1, cnt + 1);
        check[i] = false;
        sum -= num[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0; i < N; ++i){
        cin>>num[i];
    }

    dfs(0, 0);

    cout<<ans<<"\n";

    return 0;
}
