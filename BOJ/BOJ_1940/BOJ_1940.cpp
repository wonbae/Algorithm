#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m, cnt=0;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    int lt=0, rt=v.size()-1;
    sort(v.begin(), v.end());
    while(lt<rt){
        if(v[lt] + v[rt] < m) lt++;
        else if(v[lt] + v[rt] > m) rt--;
        else if(v[lt] + v[rt] == m){
            cnt++;
            lt++, rt--;
        }
    }

    cout<<cnt;

    return 0;
}