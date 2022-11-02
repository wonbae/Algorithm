#include<bits/stdc++.h>
using namespace std;

vector<int> res[15];
vector<int> arr;

void go(int st, int en, int level){
    if(st > en) return ;
    if(st == en){
        res[level].push_back(arr[st]);
        return ;
    }

    int mid = (st+en)/2;
    res[level].push_back(arr[mid]);
    go(st, mid-1, level+1);
    go(mid+1, en, level+1);

    return ;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    
    int k, num;
    cin>>k;
    int _end = pow(2,k)-1;

    for(int i = 0; i < pow(2,k)-1; i++){
        cin>>num;
        arr.push_back(num);
    }

    go(0, _end, 1);

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}