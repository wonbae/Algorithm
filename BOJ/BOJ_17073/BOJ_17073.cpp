#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n;
    double w, cnt = 0;
    cin>>n>>w;
    vector<int> tree(n+1,0);

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin>>u>>v;

        tree[u]++;
        tree[v]++;
    }

    for(int i = 2; i <= n; i++){
        if(tree[i] == 1)
            cnt++;
    }
    
    cout<<fixed;
    cout.precision(10);
    cout<<(double)(w/(double)cnt)<<"\n";
    return 0;
}