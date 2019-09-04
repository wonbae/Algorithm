#include <string>
#include <vector>
#include <iostream>

using namespace std;
int tobin(int n){
    int res = 0, tmp, count = 0;
    for(int i = 1; n > 0 ; i*=10){
        tmp = n % 2;
        if(tmp == 1){
            count++;
        }
        res += tmp * i;
        n /= 2;
    }
    // cout<<"res : "<<res<<endl;
    // cout<<"count : "<<count;
    return count;
}
int solution(int n) {
    int num = n;
    int answer = 0;
    int cnt;
    
    answer = tobin(n);
    
    while(num++){
        cnt = tobin(num);
        if(answer == cnt){
            return num;
        }
    }
    
    return answer;
}
