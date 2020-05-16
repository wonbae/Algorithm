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
    vector<ll> v;
    cin>>num;
    v.push_back(num);

    for(int i = 1; i < N; i++){
        cin>>num;
        if(v.back() < num){
            v.push_back(num);
        }else{
            ll idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }

    cout<<v.size()<<"\n";
    return 0;
}