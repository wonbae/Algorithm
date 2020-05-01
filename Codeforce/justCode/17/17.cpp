#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int N, sum = 0, num = 0, a = 0;
    cin>>N;

    while(N--){
        cin>>num>>a;
        sum = 0;
        for(int i = 1; i <= num; i++){
            sum+=i;
        }
        if(sum == a) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }


    return 0;
}