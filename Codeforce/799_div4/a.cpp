#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;

int main(){
    int t, a, b, c, d, cnt = 0;
    cin>>t;
    while(t--){
        cnt=0;
        cin>>a>>b>>c>>d;
        if(a<b){
            cnt++;
        }if(a<c){
            cnt++;
        }if(a < d){
            cnt++;
        }
        cout<<cnt<<"\n";
    }

    return 0;
}