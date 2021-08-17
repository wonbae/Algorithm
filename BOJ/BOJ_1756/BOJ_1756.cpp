#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int D, N;
int oven[300002];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
   
    cin>>D>>N;
    vector<int> dou(N);

    for(int i = 0; i < D; i++){
        cin>>oven[i];
    }
    for(int i = 0; i < N; i++){
        cin>>dou[i];
    }

    for(int i = 1; i < D; i++){
        oven[i] = min(oven[i-1], oven[i]);   
    }

    int cnt = 0, ans = D-1;

    for(int i = D-1; i >= 0; i--){
        if(cnt >= dou.size()){
            cout<<ans+1<<"\n";
            return 0;
        }
        if(oven[i] >= dou[cnt]){
            ans = i;
            cnt+=1;
        }
    }
    cout<<0<<"\n";
    return 0;
}