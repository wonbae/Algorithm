#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int main(){
    //672ms -> 280ms
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int arr[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\n";
    }

    return 0;
}