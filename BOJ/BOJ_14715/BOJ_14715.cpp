#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, cnt = 0, k = 2;
    cin>>n;

    while(n != 1){
        if (n % k == 0) {
            n /= k;
            cnt++;
        }else{
            k++;
        }
    }
    cout<<ceil(log2(cnt))<<"\n";
    return 0;
}