#include <bits/stdc++.h>
using namespace std;

int permutation(int p, int q){
    if(q == 0 || p == q) return 1;

    return permutation(p - 1, q) + permutation(p - 1, q - 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> v;
    int n,m;
    cin>>n>>m;

    // for(int i = 1; i <= n; i++){
    //     v.push_back(i);
    // }

    // do{
    //     for(int i = 0; i < m; i++){
    //         cout<<v[i]<<" ";
    //     }cout<<"\n";

    // }while(next_permutation(v.begin(), v.begin() + m));
    
    permutation(n,m);


    return 0;
}