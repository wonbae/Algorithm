#include<bits/stdc++.h>
using namespace std;

// int arr[] = {2,3,5,7,11};

bool prime(int n){
    if(n <= 1){ return false; }

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}
int main(){
    int start, end;
    cin>>start>>end;
    
    bool flag = false;
    int sum = 0, min = 10001;

    for(int i = start; i <= end; i++){
        if(prime(i)){
            sum += i;
            if(min > i){
                min = i;
            }
        }
    }

    if(sum == 0){
        cout<<-1;
    }else{
        cout<<sum<<"\n"<<min;
    }
    
    
    
    return 0;
}