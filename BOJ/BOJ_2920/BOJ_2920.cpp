#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool descending(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[8];
    int asc[8];
    int desc[8];
    int flag = 0;

    for(int i = 0; i < 8; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < 8; i++){
        asc[i] = arr[i];
        desc[i] = arr[i];
    }

    sort(asc,asc+8);
    sort(desc,desc+8,descending);

    for(int i = 0; i < 8; i++){
        if(arr[i] == asc[i]){
            flag = 1;
        }else{
            flag = 0;
            break;
        }
    }

    if(flag == 0){
        for(int i = 0; i < 8; i++){
            if(arr[i] == desc[i]){
                flag = 2;
            }else{
                flag = 0;
                break;
            }
        }
    }
    

    if(flag == 1){
        cout<<"ascending"<<"\n";
    }else if(flag == 2){
        cout<<"descending"<<"\n";
    }else{
        cout<<"mixed";
    }

    return 0;
}