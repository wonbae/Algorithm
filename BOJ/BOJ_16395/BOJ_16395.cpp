#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    if(n == 0 || r == 0 || n == r){
        return 1;
    }

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    cout<<nCr(n - 1, k - 1)<<"\n";

    return 0;
}


// #include <stdio.h>

// int main(){
//   int n,k;
//   int arr[31][31];
//   scanf("%d %d",&n,&k);

//   for(int i=0; i<31; i++){
//     arr[i][0] = 1;
//     arr[i][i] = 1;
//   }
//   for(int i=2; i<n; i++){
//     for(int j=1; j<i; j++){
//       arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//     }
//   }
//   printf("%d\n", arr[n-1][k-1]);
//   return 0;
// }