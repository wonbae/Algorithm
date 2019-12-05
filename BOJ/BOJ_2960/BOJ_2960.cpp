#include<bits/stdc++.h>
using namespace std;

#define LIMIT 1000

int main(){
    // vector<bool> isPrime(LIMIT + 1, true);   //vector 생성과 함께 초기화
    vector<bool> isPrime;       //vector 크기없이 생성만

    int n,k,count = 0;

    cin>>n>>k;

    isPrime.resize(n + 1, true);    //LIMIT 만큼 해놓을 필요가 없는듯,, 그래서 크기입력 받으면 그만큼만 벡터공간 할당

    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            for(int j = i; j <= n; j += i){ //i포함 i의 배수들을 체로 걸르듯 탐색
                if(isPrime[j]){     // 그 중에서 체크 안한 애들을 확인해서 false로 바꿈, 이거 없음 2,4,6,8,10 다음에 3,6,9 6을 두번봄
                    isPrime[j] = false;
                    count++;

                    // cout<<"delet : "<<j<<" / count : "<<count<<"\t";  

                    if(count == k){
                        cout<<j<<"\n";
                        return 0;
                    }

                }else{
                    continue;
                }
            }
            //cout<<"\n";
        }
    }

    return 0;
}