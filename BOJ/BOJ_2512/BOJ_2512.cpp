#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, lt = 0, rt = -2147000000, mid, maxi;
    ll sum;

    cin>>N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin>>v[i];
        if(v[i] > rt) rt = v[i];
        sum += v[i];
    }
    cin>>M;

    if(sum <= M){
        cout<<rt<<"\n";
        return 0;
    }

    lt = 0;

    while(lt <= rt){
        sum = 0;
        mid = (lt + rt) / 2;

        for(int i = 0; i < N; i++){
            if(v[i] <= mid){
                sum += v[i];
            }else{
                sum += mid;
            }
        }
        if(sum <= M){
            lt = mid + 1;
            maxi = mid;
        }else{
            rt = mid - 1;
        }
    }

    cout<<maxi<<"\n";
    return 0;
}