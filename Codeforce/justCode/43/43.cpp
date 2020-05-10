#include<iostream>
#include<vector>
using namespace std;

int n, v[1001];

int cal(int s){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + v[i] > s){
            cnt++;
            sum = v[i];
        }else{
            sum += v[i];
        }
    }
    return cnt;
}

int main(){
    freopen("input.txt", "rt", stdin);
    int m, lt = 0, rt = 0, mid = 0, res = 0, maxi = -2147000000;
    cin>>n>>m;
    
    for(int i = 1; i <= n; i++){
        cin>>v[i - 1];
        rt += v[i - 1];
        if(v[i - 1] > maxi) maxi = v[i - 1];
    }

    while(lt <= rt){
        mid = (lt + rt) / 2;
        
        if(mid >= maxi && cal(mid) <= m){
            res = mid;
            rt = mid - 1;
        }else{
            lt = mid + 1;
        }
    }

    cout<<res<<"\n";
    return 0;
}