#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// //N : 2 ~ 100,000,  K : 1 ~ N, 1초안에 안끊남
// int main(){
    // freopen("input.txt", "rt", stdin);
//     int N, K, arr[100001];

//     cin>>N>>K;

    // for(int i = 0; i < N; i++){
    //     cin>>arr[i];
    // }
//     int tmp = 0, max = -2147000000;
//     for(int i = 0; i < N - K; i++){
//         tmp = 0;
//         for(int j = i; j < i + K; j++){
//             tmp += arr[j];
            
//         }
//         if(max < tmp) max = tmp;
//     }

//     cout<<max<<"\n";
//     return 0;
// }

int main(){
    freopen("input.txt", "rt", stdin);
    int N, K, sum = 0, max;
    cin>>N>>K;

    vector<int> a(N);

    for(int i = 0; i < N; i++){
        cin>>a[i];
    }

    for(int i = 0; i < K; i++){
        sum += a[i];
    }
    max = sum;

    for(int i = K; i < N; i++){
        sum += a[i] - a[i - K];
        if(max < sum) max = sum;
    }

    cout<<max<<"\n";
}