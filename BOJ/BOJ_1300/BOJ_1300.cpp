#include<iostream>
using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, mid, cnt = 0, lt = 1, rt, res;
    cin>>n>>k;

    rt = k;

    while(lt <= rt){
        cnt = 0;
        mid = (lt + rt) / 2;
        for(int i = 1; i <= n; i++){
            cnt += min(mid/i, n);   //mid 보다 작은 j의 수(i * j <= mid)
        }
        if(cnt < k){
            lt = mid + 1;
        }else{
            res = mid;
            rt = mid - 1;
        }
    }

    cout<<res<<"\n";
    return 0;
}