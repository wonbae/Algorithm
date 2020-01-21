#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a > b? a : b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n,tmp;
    vector<int> v;
    

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }

    int mm = v[0];

    for(int i = 0; i < n - 1; i++){
        mm = max(v[i] + v[i + 1], mm);
    }

    cout<<mm<<"\n";

    return 0;
}