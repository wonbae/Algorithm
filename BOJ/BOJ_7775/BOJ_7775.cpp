#include<iostream>
using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int n, p, k, d;
    cin>>n>>p>>k>>d;
    d = d - 1;
    
    if(d != 0){
        int best = p - d * (d - 1) / 2;
        if(best <= d){
            cout<<"Wrong information\n";
        }else{
            cout<<best<<"\n";
            for(int i = 1; i < d; i++){
                cout<<d-i<<"\n";
            }
            for(int i = d; i < n; i++){
                cout<<0<<"\n";
            }
        }
    }else if(p % k == 0){
        for(int i = 0; i < k; i++){
            cout<<p/k<<"\n";
        }
        for(int i = k; i < n; i++){
            cout<<0<<"\n";
        }
    }else if(k < n && p / k * (n-k) >= p % k){
        int f = p/k;
        for(int i = 0; i < k; i++){
            cout<<f<<"\n";
            p-=f;
        }
        for(int i = k; i < n; i++){
            int s = min(f, p);
            cout<<s<<"\n";
            p-=s;
        }
    }else{
        cout<<"Wrong information\n";
    }
    return 0;
}