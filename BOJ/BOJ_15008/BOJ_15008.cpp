#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, a = 0, b = 0;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(),desc);

    for(int i = 0; i < n; i+=2){
        a+=v[i];
    }
    for(int i = 1; i < n; i+=2){
        b+=v[i];
    }
    cout<<a<<" "<<b;
    return 0;
}