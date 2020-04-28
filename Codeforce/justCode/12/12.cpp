#include<iostream>
#include<math.h>
using namespace std;

int main(){     //MAX Input 1,000,000,000
    
    freopen("input.txt", "rt", stdin);
    int N, sum = 0, res = 0, c = 1, d = 9;
    
    cin>>N;

    while(sum + d < N){
        res = sum + (d * c);
        sum = sum + d;
        c++;
        d = d * 10;
    }
    res = res + (N - sum) * c;
    

    cout<<res<<"\n";

    return 0;
}