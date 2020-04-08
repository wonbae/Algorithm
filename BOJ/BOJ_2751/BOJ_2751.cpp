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

////Merge Sort
// #include <bits/stdc++.h> 
// using namespace std; 
// #define endl '\n' 
// typedef long long ll; 
// #define MAXN 1000006 

// int arr[MAXN]; 
// int tmp[MAXN]; 

// void merge_sort(int arr[], int start, int end) { 
//     int mid = (start + end) / 2; 
//     if (start < mid) { 
//         merge_sort(arr, start, mid); 
//         merge_sort(arr, mid, end); 
//         int p = start, q = mid, r= start; 
        
//         while (p < mid && q < end) { 
//             if (arr[p] < arr[q]) { 
//                 tmp[r++] = arr[p++]; 
//             } 
//             else { 
//                 tmp[r++] = arr[q++]; 
//             } 
//         } 
            
//         while (p < mid) { 
//             tmp[r++] = arr[p++]; 
//         } 
        
//         while (q < end) { 
//             tmp[r++] = arr[q++]; 
            
//         } 
        
//         for (int i = start; i < end; i++)
//         { 
//              arr[i] = tmp[i]; 
//         } 
        
//     } 
// } 

// int main() {
//      ios_base::sync_with_stdio(false); 
//      cin.tie(NULL); cout.tie(NULL); 
     
//      int n; cin >> n; 
     
//      for (int i = 0; i < n; i++) { 
//          cin >> arr[i]; 
//     } 
    
//     merge_sort(arr, 0, n); 
    
//     for (int i = 0; i < n; i++) { 
//         cout << arr[i] << endl; 
//     } 
// }
