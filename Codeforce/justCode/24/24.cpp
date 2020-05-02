//Jolly Jumper 
#include<iostream>
#include<vector>
using namespace std;

int abs(int a){
    return a < 0 ? (-1) * a : a;
}
int main(){
    freopen("input.txt", "rt", stdin);
    int n, pre, now;
    // bool check[101] = {0,};
    vector<bool> check(n);
    
    cin>>n;
    cin>>pre;

    for(int i = 1; i < n; i++){
        cin>>now;
        int tmp = abs(pre - now);
        if(tmp > 0 && tmp < n && !check[tmp]){
            check[tmp] = true;
        }else{
            cout<<"NO"<<"\n";
            return 0;
        }
        pre = now;
    }

    cout<<"YES"<<"\n";

    return 0;
}