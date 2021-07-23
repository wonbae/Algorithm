#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, sum = 0;
    cin>>n;
    vector<int> v(n);
    vector<int> v2(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n; i++) cin>>v2[i];

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end(), cmp);

    for(int i = 0; i < n; i++){
        sum += v[i] * v2[i];
    }
    cout<<sum<<"\n";
    return 0;
}