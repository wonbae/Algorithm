#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int arr[5];
    for(int i = 0; i < 5; i++){
        cin>>arr[i];
    }

    int mini = 987654321;
    for(int i = 0; i < 3; i++){
        for(int j = 3; j < 5; j++){
            mini = min(arr[i] + arr[j] - 50, mini);
        }
    }

    cout<<mini<<"\n";

    return 0;
}