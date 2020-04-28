#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    string str;
    int arr[10] = {0,}, max = -2147000000;
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        int tmp = str[i] - '0';
        arr[tmp]++;
        if(max < arr[tmp]) max = tmp;
    }

    cout<<max<<"\n";

    return 0;
}