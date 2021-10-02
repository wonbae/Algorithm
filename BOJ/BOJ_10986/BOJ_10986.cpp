#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, m, cnt = 0;
    cin>>n>>m;
    vector<long long> v(n+1);
    vector<long long> tmp(m);
    tmp[0]++;
    for(int i = 1; i <= n; i++){
        int num;
        cin>>num;
        v[i] = v[i-1] + num;
        
        v[i]%=m;
        tmp[v[i]]++;
    }

    long long ans = 0;
    for(int i = 0; i < m; i++){
        ans+=tmp[i]*(tmp[i]-1)/2;
    }

    cout<<ans;
    return 0;
}