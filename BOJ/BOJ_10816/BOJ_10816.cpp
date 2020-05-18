#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);

    int N, M, num;
    cin>>N;
    vector<int> v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>num;
        cout<<upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num)<<" ";
    }
    
    return 0;
}