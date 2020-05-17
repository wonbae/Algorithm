#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll num, ans = 0, sum = 0, cnt = 1;
    cin>>num;    

    while(sum < num){
        if(sum + cnt <= num){
            sum += cnt;
            ans++;
            cnt++;
        }
        if(sum + cnt > num){
            cout<<ans<<"\n";
            break;
        }
    }

    return 0;
}