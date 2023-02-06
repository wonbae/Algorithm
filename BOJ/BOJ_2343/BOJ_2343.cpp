#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;
vector<int> v;

int calc(int s){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + v[i] > s){
            sum = v[i];
            cnt++;
        }else{
            sum += v[i];
        }
    }
    return cnt;
}

int main(){
    fastio;
    cin>>n>>m;

    int lt = 0, rt = 0, res, maxi = -987654321;

    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        v.push_back(num);
        rt += num;
        maxi = max(maxi, num);
    }        

    while(lt <= rt){
        int mid = (lt+rt)/2;

        if(calc(mid) <= m && maxi <= mid){
            res = mid;
            rt = mid - 1;
        }else{
            lt = mid + 1;
        }
    }

    cout<<res;
    return 0;
}