#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, two = 0, five = 0;
    cin>>n;
    
    for(int i = 2; i <= n; i++){
        int tmp = i;
        int idx = 2;

        while(1){
            if(tmp % idx == 0){
                tmp /= idx;
                if(idx == 2) two++;
                else if(idx == 5) five++; 
            }else{
                idx++;
            }
            if(tmp == 1) break;
        }
    }
    int res = two > five ? five : two;

    cout<<res<<"\n";

    return 0;
}