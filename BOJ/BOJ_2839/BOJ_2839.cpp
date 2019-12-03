#include <bits/stdc++.h>
using namespace std;

int solution(int &N){
    if(N < 3){
        return -1;
    }

    int count = N / 5;

    if(N % 5 == 0){
        return N/5;
    }

    while(count >= 0){
        int tmp = N - (count * 5);
        if(tmp % 3 == 0){
            return count + (tmp / 3);
        }

        count--;
    }

    return -1;

}

int main(){
    int N;
    cin>>N;

    int res = solution(N);

    cout<<res<<"\n";
    
    return 0;
}