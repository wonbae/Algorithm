#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // vector<int> v;
    int T,a;
    int min = 987654321, max = 0;

    cin>>T;
    
    while(T--){
        cin>>a;
        // v.push_back(a);
        if(a > max) max = a;
        if(a < min) min = a;
    }

    cout<<max*min<<"\n";

    return 0;
}