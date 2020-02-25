#include<iostream>
using namespace std;

int GCD(int p, int q){
    return q == 0 ? p : GCD(q, p % q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    int a, b;
    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>a>>b;
        cout<<(a * b) / GCD(a, b)<<"\n";
    }

    return 0;
}