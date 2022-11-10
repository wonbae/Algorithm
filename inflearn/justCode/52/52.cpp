// Three pointer
#include<iostream>
#include<vector>
using namespace std;

int MINI(int a, int b, int c){
    int tmp = 2147000000;
    if(a < b){
        tmp = a;
    }else tmp = b;
    if(tmp < c){
        return tmp;
    }
    return c;
}

int arr[1501] = {0,};

int main(){
    int N;
    cin>>N;

    int p2 = 1, p3 = 1, p5 = 1;
    int min = 0;

    arr[1] = 1;
    for(int i = 2; i <= N; i++){    
        min = MINI(arr[p2] * 2, arr[p3] * 3, arr[p5] * 5);
    
        if(min == arr[p2] * 2){
            p2++;
        } 
        if(min == arr[p3] * 3){
            p3++;
        }
        if(min == arr[p5] * 5){
            p5++;   
        }

        arr[i] = min;
    }

    cout<<arr[N]<<"\n";

    return 0;
}