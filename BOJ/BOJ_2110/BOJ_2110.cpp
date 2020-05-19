#include<iostream>
#include<vector>
using namespace std;

int N, v[200001];

int cal(int len){
    int cnt = 1, pos = v[0];
    for(int i = 1; i < N; i++){
        if(v[i] - pos >= len){
            cnt++;
            pos = v[i];
        }
    }
    return cnt;
}
int main(){
    int N, C, mid, lt = 1, rt = -2147000000, res = 0;
    cin>>N>>C;

    for(int i = 0; i < N; i++){
        cin>>v[i];
        if(v[i] > rt) rt = v[i];
    }

    sort(v, v+N);

    while(lt <= rt){
        mid = (lt + rt) / 2;
        if(cal(mid) >= C){
            res = mid;
            lt = mid + 1;
        }else{
            rt = mid - 1;
        }
    }

    cout<<res<<"\n";

    return 0;
}