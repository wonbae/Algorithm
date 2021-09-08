#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m, num;
    cin>>n>>m;
    
    vector<int> prefix(n);

    for(int i = 1; i <= n; i++){
        cin>>num;
        if(i > 0){
            prefix[i] = num + prefix[i-1];
        }else{
            prefix[i] = num;
        }
    }

    int x,y;
    while(m--){
        cin>>x>>y;
        cout<<prefix[y] - prefix[x-1]<<"\n";
    }
    return 0;
}