#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n;
    double t;
    cin>>n>>t;
    
    vector<double> x(n);
    vector<double> v(n);

    for(int i = 0; i < n; i++){
        cin>>x[i];
    }

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    double min_range = 2147000000, max_range = -2147000000;

    for(int i = 0; i < n; i++){
        min_range = min(min_range, round((x[i] + v[i] * t)*10000)/10000.0);
        max_range = max(max_range, round((x[i] - v[i] * t)*10000)/10000.0);
    }

    if(min_range >= max_range){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}