#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> sensor(n);
    for(int i = 0 ; i < n; i++){
        cin>>sensor[i];
    }

    if(n==k){
        cout<<0;
        return 0;
    }

    sort(sensor.begin(), sensor.end());
    for(int i = 1; i < n; i++){
        sensor[i-1] = sensor[i] - sensor[i-1];
    }    

    sort(sensor.begin(), sensor.end()-1, cmp);

    int ans = 0;
    for(int i = k-1; i < n-1; i++){
        ans+=sensor[i];
    }

    cout<<ans;
    return 0;
}