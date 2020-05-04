//Insertion Sort
#include<iostream>
using namespace std;

int main(){
    int n, arr[101], tmp = 0, i, j;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(i = 1; i < n; i++){
        tmp = arr[i];
        for(j = i - 1; j >= 0; j--){
            if(arr[j] > tmp){
                arr[j + 1] = arr[j];
            }else break;
        }
        arr[j + 1] = tmp;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}