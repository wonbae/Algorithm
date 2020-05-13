#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, lt = 0, rt = 0, cnt = 0, sum = 0;
    cin>>n>>m;
    vector<int> v(n + 1);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    while(lt <= rt){
        if(sum == m) cnt++;

        if(sum < m){
            if(rt == n) break;
            sum += v[rt++];
        }else if(sum >= m){
            sum -= v[lt++];
        }
    }

    cout<<cnt<<"\n";

    return 0;
}