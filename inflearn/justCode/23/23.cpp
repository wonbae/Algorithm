//연속부분증가수열
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    // int N, cnt = 1, max = -2147000000;
    // cin>>N;
    // vector<int> v(N);

    // for(int i = 0; i < N; i++){
    //     cin>>v[i];
    // }

    // for(int i = 0; i < N - 1; i++){
    //     if(v[i] > v[i + 1]){
    //         cnt = 1;
    //     }else if(v[i] <= v[i + 1]){
    //         cnt++;
    //         if(max < cnt) max = cnt;
    //     }
    // }

    // cout<<max<<"\n";

    freopen("input.txt", "rt", stdin);
    int n, pre, now, cnt, max;

    cin>>n;
    cin>>pre;

    cnt = 1;
    max = 1;

    for(int i = 2; i < n; i++){
        cin>>now;
        if(pre <= now){
            cnt++;
            if(max < cnt) max = cnt;
        }else{
            cnt = 1;
        }
        pre = now;
    }

    cout<<max<<"\n";

    return 0;
}