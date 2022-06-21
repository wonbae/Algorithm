#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, t;
    cin>>n>>t;
    vector<long long> v(n), pre(n+1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) pre[i+1] = pre[i] + v[i];

    while(t--){
        int x,y,sum=0;
        cin>>x>>y;
        cout<<pre[n-x+y] - pre[n-x]<<"\n";
        
    }
    return 0;
}