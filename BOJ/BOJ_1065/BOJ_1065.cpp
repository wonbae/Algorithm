#include<iostream>
using namespace std;

int main(){
    int N, ans = 99;
    cin>>N;
    if(N < 100) cout<<N<<"\n";
    else{
        for(int i = 100; i <= N; ++i){
            if((i/100) - ((i / 10) % 10) == ((i / 10) % 10) - (i%10)) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}