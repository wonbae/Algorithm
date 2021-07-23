#include<iostream>
using namespace std;

int pow(int a, int b){
    for(int i = 1; i < b; i++){
        a*=a;
    }
    return a;
}

int abs(int a){
    if(a < 0) return (-1)*a;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);

    int x1, y1, r1, x2, y2, r2, n;
    cin>>n;
    while(n--){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        int dist = pow(abs(x1 - x2),2) + pow(abs(y1 - y2),2);

        if(r1==r2 && x1 == x2 && y1 == y2){
             cout<<-1<<"\n";
        }else if(dist == pow((r1 + r2),2)){
            cout<<1<<"\n";
        }else if(dist > pow((r1 + r2),2)){
            cout<<0<<"\n";
        }else if(dist < pow((r1+r2),2)){
            if(dist > pow(abs(r1-r2),2)){
                cout<<2<<"\n";
            }else if(dist == pow(abs(r1-r2),2)){
                cout<<1<<"\n";
            }else if(dist < pow(abs(r1-r2),2)){
                cout<<0<<"\n";
            }
        }
    }
    return 0;
}