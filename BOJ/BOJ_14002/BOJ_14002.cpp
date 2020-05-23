#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int N;
    ll num;
    cin>>N;
    vector<ll> v, ans;
    vector<ll> LIS(N, 1);

    for(int i = 0; i < N; i++){     //Init
        cin>>num;
        v.push_back(num);
    }
    
    for(int i = 1; i < N; i++){     //get LIS
        for(int j = 0; j < i; j++){
            if(v[j] < v[i] && LIS[i] < LIS[j] + 1){
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    int maxi = -2147000000;         //searching max
    for(int i = 0; i < N - 1; i++){
        if(maxi < LIS[i] && v[i] < v[i + 1]){
            maxi = LIS[i];
            ans.push_back(v[i]);
        }
    }

    cout<<maxi<<"\n";
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<"\n";

    return 0;
}