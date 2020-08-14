#include<iostream>
#include<vector>
using namespace std;

int n, m, cnt = 0, sum = 0;
int arr[10];
int ch[10] = {0,};

void DFS(int L, int val){
    if(L == n + 1){
        if(val == m) cnt++;
        return ;
    }else{
        DFS(L + 1, val + arr[L-1]);
        DFS(L + 1, val - arr[L-1]);
        DFS(L + 1, val);
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    DFS(1, 0);

    if(cnt == 0) cout<<"-1"<<"\n";
    else cout<<cnt<<"\n";
    
    return 0;
}