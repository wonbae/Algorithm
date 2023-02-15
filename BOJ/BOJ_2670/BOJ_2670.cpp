#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n;
    double num, maxi = 0;
    cin>>n;
    vector<double> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    num = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > num * v[i]) num = v[i];
        else num *= v[i];
        maxi = max(maxi, num);
    }
    cout<<fixed;
    cout.precision(3);
    cout<<maxi;

    return 0;
}