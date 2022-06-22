#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int tc, n;
    string a,b;
    cin>>tc;

    while(tc--){
        cin>>n;
        map<string, int> mp;

        for(int i = 0; i < n; i++){
            cin>>a>>b;
            mp[b]++;
        }
        long long tmp = 1;
        map<string,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); iter++){
            tmp*=((long long)iter->second+1);
        }
        tmp--;
        cout<<tmp<<"\n";
    }
    return 0;
}

    // long long a, b, c;
    // cin>>a>>b>>c;
    // a%=c, b%=c;
    // long long ans = pow(a,b);
    // ans%=c;
    // cout<<ans;