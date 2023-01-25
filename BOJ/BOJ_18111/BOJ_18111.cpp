#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, m, b, ans = 2147000000, hight = 0;
    int arr[501][501];
    cin>>n>>m>>b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    for(int h = 0; h <= 256; h++){
        int build = 0;
        int flat = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int base = (arr[i][j] - h);
                if(base < 0) build -= base;
                else if(base > 0) flat += base;
            }
        }
        if(b + flat >= build){
            int time = (flat * 2) + build;
            if(time <= ans){
                ans = time;
                hight = h;
            }
        }
    }
    cout<<ans<<" "<<hight;

    return 0;
}