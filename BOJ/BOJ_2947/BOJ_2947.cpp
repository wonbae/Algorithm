#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int arr[5];
    for(int i = 0; i < 5; i++){
        cin>>arr[i];
    }
    int cnt = 5;
    int i = 0;
    while(1){
        if(i>=4) i = 0;
        if(arr[i] > arr[i+1]){
            int tmp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = tmp;
            for(int j = 0; j < 5; j++){
                cout<<arr[j]<<" ";
            }cout<<"\n";
        }
        i++;
    }

    return 0;
}