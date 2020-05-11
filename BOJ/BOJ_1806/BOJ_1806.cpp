#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, lt = 0, rt = 0, sum = 0, len = 0, minum = 987654321;
    cin>>n>>s;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    while(lt <= rt){
        if(sum < s){
            if(rt == n) break;
            sum += v[rt++];
            len++;
            
        }else if(sum >= s){
            if(minum > len) minum = len;
            sum -= v[lt++];
            len--;
        }
    }

    if(minum == 987654321){
        cout<<0<<"\n";
    }else{
        cout<<minum<<"\n";
    }
    return 0;
}