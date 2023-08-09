#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int target, m, n;
    cin>>target>>m>>n;
    vector<int> a(m), prea(m);
    vector<int> b(n), preb(n);
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    prea[0] = a[0];
    for(int i = 1; i < m; i++){
        prea[i] = a[i] + prea[i-1];
    }
    preb[0] = b[0];
    for(int i = 1; i < n; i++){
        preb[i] = b[i] + preb[i-1];
    }

    // for(int i = 0; i < m; i++){
    //     cout<<prea[i]<<" ";
    // }cout<<"\n";
    // for(int i = 0; i < n; i++){
    //     cout<<preb[i]<<" ";   
    // }

    int lt=-1, rt=-1, lt2=-1, rt2=-1;
    while(true){
        
    }


    return 0;
}