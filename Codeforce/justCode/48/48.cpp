#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int mp[9][9], avg[9], sim[9], mini;
    float sum = 0;

    for(int i = 0; i < 9; i++){
        sum = 0;
        for(int j = 0; j < 9; j++){
            cin>>mp[i][j];
            sum += mp[i][j];
        }
        avg[i] = (sum / 9.0) + 0.5;
    }

    for(int i = 0; i < 9; i++){
        mini = 2147000000;
        for(int j = 0; j < 9; j++){
            int tmp = abs(mp[i][j] - avg[i]);
            if(tmp < mini){
                mini = tmp;
                sim[i] = mp[i][j];
            }else if(tmp == mini){
                if(mp[i][j] > sim[i]) sim[i] = mp[i][j];
            }
        }
    }

    for(int i = 0; i < 9; i++){
        cout<<avg[i]<<" "<<sim[i]<<"\n";
    }
    return 0;
}