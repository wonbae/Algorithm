#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int T;
//     int k,n;
//     int arr[15][15];

//     cin>>T;
    
//     for(int tc = 0; tc < T; tc++){
//         cin>>k>>n;

//         for(int i = 0; i < n; i++){
//             arr[0][i] = i + 1;
//         }

//         for(int i = 1; i <= k; i++){
//             int sum = 0;
//             for(int j = 0; j < n; j++){
//                 sum += arr[i - 1][j];
//                 arr[i][j] = sum;
//             }
//         }

//         cout<<arr[k][n - 1]<<"\n";
        
//     }


//     return 0;
// }

int T, k, n,ch[15];
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &k, &n);
		for (int i = 1; i <= n; i++)ch[i] = i;
		for (int i = 0; i < k; i++){
			for (int j = 1; j <= n; j++){
				ch[j] += ch[j - 1];
			}
		}
		printf("%d\n", ch[n]);
	}
}