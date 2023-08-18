#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    if(n == 0){
        cout<<0;
        return 0;
    }

    deque<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int num = round((double)n*0.15);
    // cout<<num<<"\n";

    for(int i = 0; i < num; i++){
        v.pop_back();
        v.pop_front();
    }

    double sumation = 0;
    for(int i = 0; i < v.size(); i++){
        // cout<<v[i]<<" ";
        sumation += v[i];
    }
    // cout<<"\n";
    int res = round(sumation/(double)v.size());
    
    cout<<res;
    return 0;
}