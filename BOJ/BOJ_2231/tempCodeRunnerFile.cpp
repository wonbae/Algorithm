#include<bits/stdc++.h>
using namespace std;

int dividesum(int res){
    int sum = 0;
    int tmp = res;

    while(true){

        sum += tmp % 10;
        tmp /= 10;

        if(tmp <= 0){
            break;
        }
    }
    
    return sum;
}

int digit(int a){
    int cnt = 0;

    while(a > 0){
        a /= 10;
        cnt++;
    }

    return cnt;
}

int solution(int n){
    int res = n;
    vector<int> v;
    
    while(res > 0){
        int sum = 0;

        if(res < n - 9 * digit(res)){
            break;
        }

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