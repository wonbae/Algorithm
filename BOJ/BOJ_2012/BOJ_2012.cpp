#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n,a;
    long long ans = 0;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i <= arr.size(); i++){
        ans += abs(i - arr[i-1]);
    }
    cout<<ans<<"\n";
    return 0;
}