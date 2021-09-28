#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int i = 0;

    while(i<n){
        cnt += k/v[i];
        k %= v[i];
        i++;
        if(k == 0) 
            break;
    }

    cout<<cnt;
    return 0;
}