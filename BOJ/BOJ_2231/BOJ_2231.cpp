#include<bits/stdc++.h>
using namespace std;

int dividesum(int res){
    int sum = 0;
    int tmp = res;

    while(true){

        sum += tmp % 10;
        tmp = tmp / 10;

        if(tmp <= 0){
            break;
        }
    }
    
    return sum;
}


int solution(int n){
    int res = n;
    vector<int> v;
    
    while(res > 0){
        int sum = 0;

        sum = res + dividesum(res);

        if(n == sum){
            v.push_back(res);
        }

        res--;
    }

    
    if(v.empty()){
        return 0;
    }else{
        sort(v.begin(), v.end());
        res = v[0];
        return res;
    }

    
}
int main(){
    int num;
    cin>>num;

    cout<<solution(num)<<"\n";



    return 0;
}