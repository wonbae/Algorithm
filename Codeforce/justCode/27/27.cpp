#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n;
    cin>>n;
    vector<int> ch(n+1);

    for(int i = 2; i <= n; i++){
        int tmp = i;
        int j = 2;

        while(1){
            if(tmp % j == 0){
                tmp /= j;
                ch[j]++;
            }else{
                j++;
            }
            if(tmp == 1) break;
        }
    }

    cout<<n<<"! = ";
    for(int i = 2; i <= n; i++){
        if(ch[i] != 0){
            cout<<ch[i]<<" ";
        }
    }

    return 0;
}