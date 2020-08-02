// Three pointer
#include<iostream>
#include<vector>
using namespace std;

int MINI(int a, int b, int c){
    int tmp = a > b ? b : a;
    return tmp > c ? c : tmp;
}
int main(){
    int N;
    cin>>N;
    int arr[1501] = {0,};
    
    int p2 = 1, p3 = 1, p5 = 1;

    for(int i = 1; i <= N; i++){
        int min = 2147000000;
        min = MINI(p2 * 2, p3 * 3, p5 * 5);
        arr[i] = min;
        
        if(min == p2 * 2) p2++;
        else if(min == p3 * 3) p3++;
        else p5++;

    }



    return 0;
}