#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, ans;
double a[11], num, sum;

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>num;
        a[i] = (100/num);
    }

    for(int i = 1; i < (1<<n); i++){
        sum=0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                // cout<<a[j]<<" ";
                sum+=a[j];
            }
        }
        // cout<<"\nsum : "<<sum<<"\n\n";
        if(99 <= sum && sum <= 101) ans++;
    }
    cout<<ans;
    return 0;
}