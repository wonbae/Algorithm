#include<iostream>
// #include<vector>
// #include<math.h>
using namespace std;

int num[101];

int reverse(int x){
    // int nNum = 0, tmp = 0, res = 0, len = 0;
    // vector<int> v;

    // tmp = x;
    // while(tmp > 0){
    //     res = tmp % 10;

    //     if(res == 0){
    //         tmp = tmp / 10;
    //     }
    //     else{
    //         v.push_back(res);
    //         tmp = tmp / 10;
    //         len++;
    //     }
    // }

    // for(int i = 0; i < v.size(); i++){
    //     nNum += v[i] * pow(10, len - 1);
    //     len--;
    // }

    int res = 0, tmp = 0;
    while(x > 0){
        tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }

    return res;
}

bool isPrime(int x){
    if(x == 1) return false;
    
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    freopen("input.txt", "rt", stdin);

    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>num[i];
    }

    for(int i = 0; i < T; i++){
        num[i] = reverse(num[i]);
        if(isPrime(num[i])){
            cout<<num[i]<<" ";
        }
    }

    return 0;
}