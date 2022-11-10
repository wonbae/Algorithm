#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k, pos = 0, cnt = 0, bp = 0;
    cin>>n>>k;
    vector<int> v(n + 1);

    while(1){
        pos++;

        if(pos > n){
            pos = 1;
        }

        if(v[pos] == 0){
            cnt++;
            if(cnt == k){
                cnt = 0;
                v[pos] = 1;
                bp++;
            }
        }

        if(bp == n - 1) break;
    }
    
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            cout<<i<<"\n"; 
            break;
        } 
    }

    return 0;
}