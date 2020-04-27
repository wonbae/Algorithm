#include<iostream>
#include<math.h>
using namespace std;

int main(){     //MAX Input 1,000,000,000
    
    freopen("input.txt", "rt", stdin);
    int N, sum = 0, tmp, len = 0, res = 0;
    
    cin>>N;
    tmp = N;
    while(tmp > 0){
        tmp /= 10;
        len++;
    }

    for(int i = 1; i <= len; i++){
        if(9 * pow(10, i - 1) > N){
            res = N - sum * i + 1;
        }else{
            sum += 9 * pow(10, i - 1);
        }
    }

    cout<<res<<"\n";

    return 0;
}