#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, cnt = 0, cnt2 = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        if(a==b) continue;
        if(a == 1 && b == 3){
            cnt++;
        }else if(a == 3 && b == 2){
            cnt++;
        }else if(a == 2 && b == 1){
            cnt++;
        }else{
            cnt2++;
        }
    }
    if(cnt2<cnt){
        cout<<cnt<<"\n";
    }else{
        cout<<cnt2<<"\n";
    }
    
    return 0;
}