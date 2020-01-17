#include<bits/stdc++.h>
using namespace std;

// 여기서 T가 최대가 10,000,000 이다. 배열에 담을려고 하면 다 못담는다 
//int 배열의 최대 크기가 약 이십오만 이란다, 
// 입력값이 백만 이상이면 그냥 다른방법을 사용하자

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num;
    int array[10001];
    int T;

    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>num;
        array[num]++;
    }

    for(int i = 0; i <10000; i++){
        for(int j = 0; j < array[i]; j++){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}