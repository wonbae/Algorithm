#include<iostream>
#include<vector>
using namespace std;
#define SIZE 200001

int arr[SIZE], n;

int cal(int len){
    int cnt = 1, pos = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - pos >= len){
            cnt++;
            pos = arr[i];
        }
    }
    return cnt;
}

int main(){
    freopen("input.txt", "rt", stdin);
    int c, lt = 0, rt = -2147000000, mid = 0, res = 0;
    cin>>n>>c;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] > rt) rt = arr[i];
    }

    sort(arr, arr+n);

    while(lt <= rt){
        mid = (lt + rt) / 2;
        if(cal(mid) >= c){
            res = mid;
            lt = mid + 1;
            
        }else{
            rt = mid - 1;
        }
    }

    cout<<res<<"\n";
    return 0;
}