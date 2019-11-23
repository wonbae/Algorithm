#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[9];
    int max = 0, idx = 0;

    for(int i = 0; i < 9; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < 9; i++){
        if(max < arr[i]){
            max = arr[i];
            idx = i;
        }
    }

    cout<<max<<"\n"<<idx + 1;

    return 0;
}