
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N = 0,M,input,target;
    int arr[MAX] = {0,};
    
    cin>>N;


    for(int i = 0; i < N; i++){
        // cin>>input;
        // arr[input]++;
        cin>>arr[i];
    }

    sort(arr, arr+N);

    // for(int i = 0; i < N; i++){
    //     cout<<arr[i]<<" ";
    // }

    cin>>M;

    

    for(int i = 0; i < M; i++){
        int s = 0, e = N - 1, mid;
        bool flag = true;

        cin>>target;

        // if(arr[compare] != 0){
        //     cout<<"1"<<"\n";
        // }else{
        //     cout<<"0"<<"\n";
        // }

        while(s <= e){
            mid = (s + e)/2;

            if(arr[mid] == target){
                flag = false;
                cout<<"1"<<"\n";
                break;
            } 
            else if(arr[mid] > target){
                e = mid - 1;

            }else if(arr[mid] < target){
                s = mid + 1;
            }
            
        }
        if(flag){
            cout<<"0"<<"\n";
        }
        
    }

    return 0;
}