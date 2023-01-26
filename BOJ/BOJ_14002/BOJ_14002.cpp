#include<bits/stdc++.h>
using namespace std;

int N;
int prevs[1004], LIS[1004], v[1004];


void go(int idx){
    if(idx==-1) return;
    go(prevs[idx]);
    cout<<v[idx]<<" ";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin>>N;

    fill(prevs, prevs+1004, -1);
    fill(LIS, LIS+1004, 1);

    for(int i = 0; i < N; i++){     //Init
        cin>>v[i];
    }
 
    for(int i = 0; i < N; i++){     //get LIS
        for(int j = 0; j < i; j++){
            if(v[j] < v[i] && LIS[i] < LIS[j] + 1){
                LIS[i] = LIS[j] + 1;
                prevs[i] = j;
             }
        }
    }

    int maxi = 1;         //searching max
    int idx = 0;
    for(int i = 0; i < N; i++){
        if(maxi < LIS[i]){
            maxi = LIS[i];
            idx = i;
        }
    }
    cout<<maxi<<"\n";
    go(idx);

    // for(int i = idx; i != -1; i = prevs[i]){
    //     // cout<<v[i]<<" ";
    // }
    return 0;
}