#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int arr[5];
    for(int i = 0; i < 5; i++){
        cin>>arr[i];
    }

    while(1){
        for(int i = 0; i < 4; i++){
            bool tik = false;
            if(arr[i] > arr[i+1]){
                int tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
                tik = true;
            }
            if(tik){
                for(int j = 0; j < 5; j++){
                    cout<<arr[j]<<" ";
                }cout<<"\n";
            }
        }

        bool flag = false;
        for(int i = 0; i < 4; i++){
            if(arr[i] < arr[i+1]) continue;
            else{
                flag = true;
                break;
            }
        }
        
        if(!flag) break;

    }

    return 0;
}