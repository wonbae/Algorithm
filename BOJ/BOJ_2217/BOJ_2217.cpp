#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    long long ans = 0;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        long long w = (i+1) * v[i];
        ans = max(ans, w);
    }

    cout<<ans;

    return 0;
}