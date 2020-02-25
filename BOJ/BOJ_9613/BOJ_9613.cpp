#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    int arr[100];

    cin>>T;

    while(T--){
        int len = 0;
        long long sum = 0;

        cin>>len;

        for(int i = 0; i < len; i++){
            cin>>arr[i];
        }

        for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                sum += GCD(arr[i], arr[j]);
            }
        }

        cout<<sum<<"\n";
    }
    return 0;
}