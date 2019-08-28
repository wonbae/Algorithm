#include <iostream>
using namespace std;

int res = 0;

int recul(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;

    res = recul(n-1) + recul(n-2) + recul(n - 3);

    return res;
}
int main(){
    int T,N;
    cin>>T;
    for(int tc = 0; tc < T; tc++){
        cin>>N;
        cout<<recul(N)<<endl;
    }
    
    return 0;
}