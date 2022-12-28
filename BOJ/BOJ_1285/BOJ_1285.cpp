#include<bits/stdc++.h>
using namespace std;

int n, res=2147000000;
int a[21];
string str;

void dfs(int here){
    if(here == n+1){
        int sum = 0;
        for(int i = 1; i <= (1<<(n-1)); i*=2){ //1,2,4
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if(a[j] & i) cnt++;
            }
            sum += min(n-cnt, cnt);
        }
        res = min(res, sum);
        return;
    }
    dfs(here+1);
    a[here] = ~a[here];
    dfs(here+1);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>str;
        // int num = 1;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == 'T') a[i] |= (1<<j);
            // if(str[j] == 'T') a[i] |= num;
            // num*=2;
        }
    }    

    dfs(1);
    cout<<res<<"\n";
    return 0;
}