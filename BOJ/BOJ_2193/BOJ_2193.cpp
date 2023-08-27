#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;

    vector<long long> v(n+1);

    v[1] = 1;
    v[2] = 1;

    for(int i = 3; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }

    cout<<v[n];

    return 0;
}