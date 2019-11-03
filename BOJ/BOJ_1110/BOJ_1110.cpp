#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, count = 0;
    cin>>n;

    int r = n % 10;
    int l = n / 10;

    while(1){
        int N = (r * 10) + ((r + l)%10);

        // cout<<N<<",";
        count++;

        if(n == N){
            break;
        }

        r = N % 10;
        l = N / 10;
        // cout<<l<<" + "<<r<<"\n";
    }
    
    cout<<count;


    return 0;
}