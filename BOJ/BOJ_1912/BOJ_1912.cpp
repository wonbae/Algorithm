#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
    int n, sum=0, ans=-1004, num;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>num;
        sum += num;
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
    }

    cout<<ans;
    return 0;
}