#include<iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, candi[10001], maxi, carlos;

    cin>>n;
    cin>>carlos;
    maxi = carlos;

    for(int i = 1; i < n; i++){
        cin>>candi[i];
        maxi = max(candi[i], maxi);
    }

    if(carlos == maxi){
        cout<<"S";
    }else{
        cout<<"N";
    }
    return 0;
}